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
 * APDUProxyStack.h
 *
 *  Created on: Jul 24, 2012
 *      Author: asorbini
 */

#ifndef APDUPROXYSTACK_H_
#define APDUPROXYSTACK_H_

#include "Stack.h"
#include "APDUProxy.h"
#include "APDUProxyStackConfig.h"
#include "VtoReader.h"
#include "VtoWriter.h"

namespace apl {
namespace dnp {

class APDUProxyStack : public Stack {
public:
	APDUProxyStack(
			const string& proxyName,
	        Logger* logger,
	        ITimerSource* timerSrc,
	        APDUProxyStackConfig& cfg);

	IVtoWriter* GetVtoWriter() { return &vtoWriter; }
	IVtoReader* GetVtoReader() { return &vtoReader; };


	APDUProxyStackConfig config;
	APDUProxy* proxy;

	VtoReader vtoReader;
	VtoWriter vtoWriter;
};



}
}


#endif /* APDUPROXYSTACK_H_ */
