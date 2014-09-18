/* Copyright 2014 Real-Time Innovations, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
/*
 * APDUProxyImpl.cpp
 *
 *  Created on: Jul 26, 2012
 *      Author: asorbini
 */

#include <iostream>
#include <stdio.h>

#include "APDUProxy.h"
#include "APDUProxyImpl.h"
/*
 #include <boost/thread/condition.hpp>
 #include <boost/thread/shared_mutex.hpp>
 */

namespace apl {
namespace dnp {

using namespace boost;

bool APDUProxyImpl::AddAPDUListener(
		APDUListener* listener) {
	string& listName = listener->getName();
	LOG_BLOCK(LEV_INTERPRET, "Adding new listener " << listName);
	this->listeners.push_back(listener);
	return true;
}

bool APDUProxyImpl::RemoveAPDUListener(
		APDUListener* listener) {
	string& listName = listener->getName();
	LOG_BLOCK(LEV_WARNING,
			"Removal of listeners not implemented yet. Cannot remove : " << listName);
	return false;
}

CommandStatus APDUProxyImpl::SendRequestAPDU(
		APDU& apdu) {

	LOG_BLOCK(LEV_INTERPRET, "SendRequestAPDU " << apdu.ToString());
	unique_lock<recursive_timed_mutex> lock(this->globalMutex);
	while (this->currentOp != PO_NONE) {
		LOG_BLOCK(LEV_INTERPRET,
				"SendRequestAPDU - waiting for current operation to end : "<<this->currentOp);
		this->sendCondition.wait(lock);
	}
	this->currentOp = PO_SEND_REQUEST;

	CommandStatus result = CS_HARDWARE_ERROR;

	try {
		LOG_BLOCK(LEV_INTERPRET, "SendRequestAPDU - Sending APDU...");
		this->appLayer->SendRequest(apdu);

	} catch (apl::Exception& ex) {
		LOG_BLOCK(LEV_ERROR, "Exception sending request: " << ex.what());
		this->currentOp = PO_NONE;
		return CS_HARDWARE_ERROR;
	}

	while (!this->hasResult) {
		LOG_BLOCK(LEV_INTERPRET,
				"SendRequestAPDU - Waiting for send outcome...");
		this->sendOutcomeCondition.wait(lock);
	}
	this->hasResult = false;

	result = this->sendResults.front();
	this->sendResults.pop_front();

	LOG_BLOCK(LEV_INTERPRET, "SendRequestAPDU - Result : "<< result);

	this->currentOp = PO_NONE;
	this->sendCondition.notify_all();

	return result;

}

CommandStatus APDUProxyImpl::SendResponseAPDU(
		APDU& apdu) {

	LOG_BLOCK(LEV_INTERPRET, "SendResponseAPDU " << apdu.ToString());
	unique_lock<recursive_timed_mutex> lock(this->globalMutex);
	while (this->currentOp != PO_NONE) {
		LOG_BLOCK(LEV_INTERPRET,
				"SendResponseAPDU - waiting for current operation to end : "<<this->currentOp);
		this->sendCondition.wait(lock);
	}
	this->currentOp = PO_SEND_RESPONSE;

	CommandStatus result = CS_HARDWARE_ERROR;

	try {
		LOG_BLOCK(LEV_INTERPRET, "SendResponseAPDU - sending APDU...");
		this->appLayer->SendResponse(apdu);

	} catch (apl::Exception& ex) {
		LOG_BLOCK(LEV_ERROR, "Exception sending RESPONSE: " << ex.what());
		this->currentOp = PO_NONE;
		return CS_HARDWARE_ERROR;
	}
//	this->sendResultsSemaphore.wait();

	while (!this->hasResult) {
		LOG_BLOCK(LEV_INTERPRET,
				"SendResponseAPDU - Waiting for send outcome...");
		this->sendOutcomeCondition.wait(lock);
	}
	this->hasResult = false;

	result = this->sendResults.front();
	this->sendResults.pop_front();

	LOG_BLOCK(LEV_INTERPRET, "SendResponseAPDU - Result : "<< result);

	this->currentOp = PO_NONE;
	this->sendCondition.notify_all();

	return result;
}

CommandStatus APDUProxyImpl::SendUnsolResponseAPDU(
		APDU& apdu) {

	LOG_BLOCK(LEV_INTERPRET, "SendUnsolResponseAPDU " << apdu.ToString());
	unique_lock<recursive_timed_mutex> lock(this->globalMutex);
	while (this->currentOp != PO_NONE) {
		LOG_BLOCK(LEV_INTERPRET,
				"SendUnsolResponseAPDU - waiting for current operation to end : "<<this->currentOp);
		this->sendCondition.wait(lock);
	}
	this->currentOp = PO_SEND_UNSOL;

	CommandStatus result = CS_HARDWARE_ERROR;

	try {
		LOG_BLOCK(LEV_INTERPRET, "SendUnsolResponseAPDU - Sending APDU...");
		this->appLayer->SendUnsolicited(apdu);
	} catch (apl::Exception& ex) {
		LOG_BLOCK(LEV_ERROR, "Exception sending UNSOL: " << ex.what());
		this->currentOp = PO_NONE;
		return CS_HARDWARE_ERROR;
	}
//	this->sendResultsSemaphore.wait();

	while (!this->hasResult) {
		LOG_BLOCK(LEV_INTERPRET,
				"SendUnsolResponseAPDU - Waiting for send outcome...");
		this->sendOutcomeCondition.wait(lock);
	}
	this->hasResult = false;

	result = this->sendResults.front();
	this->sendResults.pop_front();

	LOG_BLOCK(LEV_INTERPRET, "SendUnsolResponseAPDU - Result : "<< result);

	this->currentOp = PO_NONE;
	this->sendCondition.notify_all();

	return result;
}

void APDUProxyImpl::OnLowerLayerUp() {
	LOG_BLOCK(LEV_INTERPRET, "OnLowerLayerUp");

	/*this->lowerLayerUp = true;*/
}

void APDUProxyImpl::OnLowerLayerDown() {
	LOG_BLOCK(LEV_INTERPRET, "OnLowerLayerDown");

	/*this->lowerLayerUp = false;*/

}

void APDUProxyImpl::OnUnsolSendSuccess() {
	LOG_BLOCK(LEV_INTERPRET, "OnUnsolSendSuccess");
	unique_lock<recursive_timed_mutex> lock(this->globalMutex);
	this->sendResults.push_back(CS_SUCCESS);
	this->hasResult = true;
	this->sendOutcomeCondition.notify_all();
	LOG_BLOCK(LEV_INTERPRET, "OnUnsolSendSuccess - notified");

}

void APDUProxyImpl::OnUnsolFailure() {
	LOG_BLOCK(LEV_INTERPRET, "OnUnsolFailure");
	unique_lock<recursive_timed_mutex> lock(this->globalMutex);

	this->sendResults.push_back(CS_HARDWARE_ERROR);

	this->hasResult = true;
	this->sendOutcomeCondition.notify_all();
	LOG_BLOCK(LEV_INTERPRET, "OnUnsolFailure - notified");
}

void APDUProxyImpl::OnSolSendSuccess() {
	LOG_BLOCK(LEV_INTERPRET, "OnSolSendSuccess");
	unique_lock<recursive_timed_mutex> lock(this->globalMutex);

	this->sendResults.push_back(CS_SUCCESS);

	this->hasResult = true;
	this->sendOutcomeCondition.notify_all();

	LOG_BLOCK(LEV_INTERPRET, "OnSolSendSuccess - notified");
}

void APDUProxyImpl::OnSolFailure() {
	LOG_BLOCK(LEV_INTERPRET, "OnSolFailure");
	unique_lock<recursive_timed_mutex> lock(this->globalMutex);

	this->sendResults.push_back(CS_HARDWARE_ERROR);

	this->hasResult = true;
	this->sendOutcomeCondition.notify_all();
	LOG_BLOCK(LEV_INTERPRET, "OnSolFailure - notified");
}

bool APDUProxyImpl::IsMaster() {
	return this->config.isMaster;
}

void APDUProxyImpl::OnPartialResponse(
		const APDU& apdu) {
	LOG_BLOCK(LEV_INTERPRET, "OnPartialResponse : "<< apdu.ToString());
	{
		unique_lock<recursive_timed_mutex> lock(this->globalMutex);

		APDU * received = new APDU(apdu);
		this->responseAPDUs.push_back(received);
		this->sendResults.push_back(CS_SUCCESS);

		this->hasResult = true;
		this->sendOutcomeCondition.notify_all();
		lock.unlock();
	}

	{
		unique_lock<recursive_timed_mutex> lock(this->notificationMutex);
		this->hasMessages = true;
		this->notifyListenersCondition.notify_all();
		lock.unlock();
	}

	LOG_BLOCK(LEV_INTERPRET, "OnPartialResponse - notified");
}

void APDUProxyImpl::OnFinalResponse(
		const APDU& apdu) {

	LOG_BLOCK(LEV_INTERPRET, "OnFinalResponse : "<< apdu.ToString());
	{
		unique_lock<recursive_timed_mutex> lock(this->globalMutex);
		APDU * received = new APDU(apdu);
		this->responseAPDUs.push_back(received);
		this->sendResults.push_back(CS_SUCCESS);
		this->hasResult = true;
		this->sendOutcomeCondition.notify_all();
		lock.unlock();
	}

	{
		unique_lock<recursive_timed_mutex> lock(this->notificationMutex);
		this->hasMessages = true;
		this->notifyListenersCondition.notify_all();
		lock.unlock();
	}

	LOG_BLOCK(LEV_INTERPRET, "OnFinalResponse - notified");
}

void APDUProxyImpl::OnUnsolResponse(
		const APDU& apdu) {

	LOG_BLOCK(LEV_INTERPRET, "OnUnsolResponse : "<< apdu.ToString());
	{
		unique_lock<recursive_timed_mutex> lock(this->notificationMutex);
		APDU * received = new APDU(apdu);
		this->unsolResponseAPDUs.push_back(received);
		this->hasMessages = true;
		this->notifyListenersCondition.notify_all();
		lock.unlock();
	}
	LOG_BLOCK(LEV_INTERPRET, "OnUnsolResponse - notified");
}

void APDUProxyImpl::OnRequest(
		const APDU& apdu, SequenceInfo info) {
	LOG_BLOCK(LEV_INTERPRET, "OnRequest: "<< apdu.ToString());
	{
		unique_lock<recursive_timed_mutex> lock(this->globalMutex);

		APDU * received = new APDU(apdu);
		this->requestAPDUs.push_back(received);
		lock.unlock();
	}

	LOG_BLOCK(LEV_INTERPRET, "OnRequest - notifying notifier...");
	{
		unique_lock<recursive_timed_mutex> lock(this->notificationMutex);
		this->hasMessages = true;
		this->notifyListenersCondition.notify_all();
		lock.unlock();
	}

	LOG_BLOCK(LEV_INTERPRET, "OnRequest - notified");
}

void APDUProxyImpl::OnUnknownObject() {

	LOG_BLOCK(LEV_INTERPRET, "OnUnknownObject");

}

void APDUProxyImpl::_OnUnsolResponse() {

	while (!this->unsolResponseAPDUs.empty()) {
		APDU& apdu = this->unsolResponseAPDUs.front();

		LOG_BLOCK(LEV_INTERPRET, "Notifying UNSOL APDU : "
				<< apdu.ToString());

		for (boost::ptr_vector<APDUListener>::size_type i = 0;
				i < this->listeners.size(); i++) {
			APDUListener& listener = this->listeners[i];
			listener.newResponseAPDU((APDUProxy*) this,
					const_cast<APDU&>(apdu));
		}

		this->unsolResponseAPDUs.pop_front();
	}

}

void APDUProxyImpl::_OnResponse() {

	while (!this->responseAPDUs.empty()) {
		APDU& apdu = this->responseAPDUs.front();

		LOG_BLOCK(LEV_INTERPRET, "Notifying RESPONSE APDU : "
				<< apdu.ToString());

		for (boost::ptr_vector<APDUListener>::size_type i = 0;
				i < this->listeners.size(); i++) {
			APDUListener& listener = this->listeners[i];
			listener.newResponseAPDU((APDUProxy*) this,
					const_cast<APDU&>(apdu));
		}

		this->responseAPDUs.pop_front();
	}

}

void APDUProxyImpl::_OnRequest() {

	while (!this->requestAPDUs.empty()) {
		APDU& apdu = this->requestAPDUs.front();

		LOG_BLOCK(LEV_INTERPRET, "Notifying REQUEST APDU : "
				<< apdu.ToString());

		for (boost::ptr_vector<APDUListener>::size_type i = 0;
				i < this->listeners.size(); i++) {
			APDUListener& listener = this->listeners[i];
			listener.newRequestAPDU((APDUProxy*) this,
					const_cast<APDU&>(apdu));
		}

		this->requestAPDUs.pop_front();
	}

}

void APDUProxyImpl::Run(
		APDUProxyImpl* proxy) {

	while (proxy->active) {
		LOGGER_BLOCK(proxy->mpLogger, LEV_INTERPRET,
				"NotificationThread - begin iteration");
		unique_lock<recursive_timed_mutex> lock(proxy->notificationMutex);

		while (!proxy->hasMessages) {
			LOGGER_BLOCK(proxy->mpLogger, LEV_INTERPRET,
					"NotificationThread - waiting for APDU to notify...");
			proxy->notifyListenersCondition.wait(lock);
		}

		LOGGER_BLOCK(proxy->mpLogger, LEV_INTERPRET,
				"NotificationThread - notifying APDUs");
		proxy->_OnRequest();
		proxy->_OnResponse();
		proxy->_OnUnsolResponse();

		proxy->hasMessages = false;
		LOGGER_BLOCK(proxy->mpLogger, LEV_INTERPRET,
				"NotificationThread - end of iteration");
		/*boost::this_thread::sleep(boost::posix_time::milliseconds(100));*/
	}

}

}
}

