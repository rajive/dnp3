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
 * APDUProxyStackConfig.h
 *
 *  Created on: Jul 24, 2012
 *      Author: asorbini
 */

#ifndef APDUPROXYSTACKCONFIG_H_
#define APDUPROXYSTACKCONFIG_H_

#include <APL/Types.h>
#include "DNPConstants.h"
#include "APDUProxyConfig.h"
#include "AppConfig.h"
#include "LinkConfig.h"

namespace apl {
namespace dnp {

class APDUProxyStackConfig {
public:
	APDUProxyStackConfig(
				boost::uint16_t localAddr,
				boost::uint16_t remoteAddr,
				bool isMaster = false,
				bool useConfirms = false,
				millis_t linkTimeout = 1000,
				millis_t appTimeout = 1000,
				size_t numRetry = 0,
				size_t fragSize = DEFAULT_FRAG_SIZE) :
				proxy(isMaster,localAddr,remoteAddr),
				app(appTimeout, numRetry, fragSize, isMaster, localAddr, remoteAddr),
				link(isMaster,useConfirms, numRetry, localAddr, remoteAddr, linkTimeout)
				{}

	void dump();

	APDUProxyConfig proxy; // APDUProxy config
	AppConfig app;		  // Application layer config
	LinkConfig link;	  // Link layer config

};

}
}



#endif /* APDUPROXYSTACKCONFIG_H_ */
