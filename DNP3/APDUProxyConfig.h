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
 * APDUProxyConfig.h
 *
 *  Created on: Jul 26, 2012
 *      Author: asorbini
 */

#ifndef APDUPROXYCONFIG_H_
#define APDUPROXYCONFIG_H_

#include <APL/Types.h>

namespace apl {
namespace dnp {

class APDUProxyConfig {
public :
	APDUProxyConfig(
			bool isMaster = false,
			boost::uint16_t localAddr = 0,
			boost::uint16_t remoteAddr = 1) :
			isMaster(isMaster),
			localAddr(localAddr),
			remoteAddr(remoteAddr)
			{}

	bool isMaster;
	boost::uint16_t localAddr;
	boost::uint16_t remoteAddr;
};

}
}


#endif /* APDUPROXYCONFIG_H_ */
