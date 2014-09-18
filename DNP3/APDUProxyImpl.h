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
 * APDUProxyImpl.h
 *
 *  Created on: Jul 26, 2012
 *      Author: asorbini
 */

#ifndef APDUPROXYIMPL_H_
#define APDUPROXYIMPL_H_

/*#include <map>*/
#include <deque>
#include <boost/ptr_container/ptr_vector.hpp>
#include <boost/ptr_container/ptr_deque.hpp>

/*
 #include <boost/interprocess/sync/interprocess_semaphore.hpp>
 #include <boost/interprocess/sync/interprocess_mutex.hpp>
 #include <boost/interprocess/sync/interprocess_condition.hpp>
 #include <boost/interprocess/sync/scoped_lock.hpp>
 */

#include <boost/thread/recursive_mutex.hpp>
#include <boost/thread/condition_variable.hpp>
#include <boost/thread/locks.hpp>

#include <boost/thread.hpp>

#include <APL/Logger.h>
#include <APL/Loggable.h>
#include <APL/LogTypes.h>

#include "APL/Lock.h"
#include "APL/IOService.h"
#include "APL/TimerSourceASIO.h"

#include "AppLayer.h"
#include "APDUProxy.h"
#include "APDUProxyConfig.h"

namespace apl {
namespace dnp {

enum APDUProxyOperation {
	PO_NONE, PO_SEND_REQUEST, PO_SEND_RESPONSE, PO_SEND_UNSOL
};

class APDUProxyImpl: public APDUProxy {
private:

	AppLayer* appLayer;
	Logger* mpLogger;

	boost::ptr_vector<APDUListener> listeners;

	boost::ptr_deque<APDU> responseAPDUs;
	boost::ptr_deque<APDU> unsolResponseAPDUs;
	boost::ptr_deque<APDU> requestAPDUs;

	bool lowerLayerUp;

	std::deque<CommandStatus> sendResults;

	/*boost::interprocess::interprocess_mutex sendMutex;
	 boost::interprocess::interprocess_condition sendCondition;
	 boost::interprocess::interprocess_condition sendOutcomeCondition;*/
	boost::recursive_timed_mutex globalMutex;
	boost::condition_variable_any sendCondition;
	boost::condition_variable_any sendOutcomeCondition;
	boost::recursive_timed_mutex notificationMutex;
	boost::condition_variable_any notifyListenersCondition;

	bool hasResult;
	bool hasMessages;
	APDUProxyOperation currentOp;

	boost::posix_time::seconds sleepTime;
	bool active;
	boost::thread* listeningThread;

	virtual void _OnRequest();
	virtual void _OnResponse();
	virtual void _OnUnsolResponse();
	static void Run(
			APDUProxyImpl*);

public:
	APDUProxyImpl(
			const string& proxyName,
			APDUProxyConfig& cfg,
			AppLayer* appLayer, Logger* logger) :
			appLayer(appLayer),
			mpLogger(logger),
					listeners(),
					responseAPDUs(),
					unsolResponseAPDUs(),
					requestAPDUs(),
					lowerLayerUp(false),
					sendResults(),
					globalMutex(),
					notificationMutex(),
					sendCondition(),
					sendOutcomeCondition(),
					notifyListenersCondition(),
					hasResult(false),
					hasMessages(false),
					currentOp(PO_NONE),
					sleepTime(3),
					active(false),
					listeningThread(NULL),
					name(proxyName),
					config(cfg) {

		this->start();

	}

	~APDUProxyImpl() {
	}
	;

	void start() {
		if (this->listeningThread == NULL) {
			this->active = true;
			this->listeningThread = new boost::thread(&APDUProxyImpl::Run,
					this);
		}
	}

	void stop() {
		this->active = false;
		this->listeningThread = NULL;
	}

	bool AddAPDUListener(
			APDUListener*);
	bool RemoveAPDUListener(
			APDUListener*);
	CommandStatus SendRequestAPDU(
			APDU&);
	CommandStatus SendResponseAPDU(
			APDU&);
	CommandStatus SendUnsolResponseAPDU(
			APDU&);

	virtual void OnLowerLayerUp();
	virtual void OnLowerLayerDown();

	virtual void OnUnsolSendSuccess();
	virtual void OnUnsolFailure();

	virtual void OnSolSendSuccess();
	virtual void OnSolFailure();

	virtual bool IsMaster();

	virtual void OnPartialResponse(
			const APDU&);

	virtual void OnFinalResponse(
			const APDU&);

	virtual void OnUnsolResponse(
			const APDU&);

	virtual void OnRequest(
			const APDU&, SequenceInfo);

	virtual void OnUnknownObject();

	string name;

	APDUProxyConfig config;

};

}
}

#endif /* APDUPROXYIMPL_H_ */
