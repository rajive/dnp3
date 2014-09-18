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
 * APDUProxyStack.cpp
 *
 *  Created on: Jul 24, 2012
 *      Author: asorbini
 */

#include "APL/Logger.h"
#include "APDUProxyStack.h"
#include "APDUProxyImpl.h"

#include <iostream>

namespace apl {
namespace dnp {

void APDUProxyStackConfig::dump() {
	/*cout << "APDUProxyStackConfig: appConfig.localAddr=" << this->app.LocalAddr
			<< ", appConfig.remoteAddr=" << this->app.RemoteAddr
			<< ", appConfig.IsMaster=" << this->app.IsMaster << "\n";
	cout << "APDUProxyStackConfig: linkConfig.localAddr="
			<< this->link.LocalAddr << ", linkConfig.remoteAddr="
			<< this->link.RemoteAddr << ", linkConfig.IsMaster="
			<< this->link.IsMaster << "\n";*/
}

APDUProxyStack::APDUProxyStack(
		const string& proxyName,
		Logger* logger,
		ITimerSource* timerSrc,
		APDUProxyStackConfig& cfg) :
		Stack(logger, timerSrc, cfg.app, cfg.link),
				config(cfg),
				vtoReader(logger),
				vtoWriter(logger->GetSubLogger("VtoWriter"), 10) {

	/*cfg.dump();*/

	this->proxy = new APDUProxyImpl(proxyName, cfg.proxy, &(this->mApplication),
			logger);
	this->mApplication.SetUser((IAppUser*) this->proxy);
}

}
}

