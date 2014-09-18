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
 * APDUInfoProvider.h
 *
 *  Created on: Jul 24, 2012
 *      Author: asorbini
 */

#ifndef APDUINFOPROVIDER_H_
#define APDUINFOPROVIDER_H_


#include <APL/Types.h>
#include "APDU.h"

namespace apl {

namespace dnp {


class APDUInfoProvider {
public :
	virtual ~APDUInfoProvider() = 0;
	virtual void NewDataLinkFrame(boost::uint16_t src, bool master, boost::uint16_t dest) = 0;
	virtual void NewAPDU(APDU&) = 0;
};


}
}

#endif /* APDUINFOPROVIDER_H_ */
