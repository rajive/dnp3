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
 * APDUProxy.h
 *
 *  Created on: Jul 24, 2012
 *      Author: asorbini
 */

#ifndef APDUPROXY_H_
#define APDUPROXY_H_

#include <APL/CommandTypes.h>

#include "AppInterfaces.h"
#include "APDU.h"
#include "APDUListener.h"

namespace apl {
namespace dnp {

class APDUProxy : public IAppUser {
public:
	virtual ~APDUProxy() {};

	virtual bool AddAPDUListener(APDUListener*) { return false; };
	virtual bool RemoveAPDUListener(APDUListener*) { return false; };
	virtual CommandStatus SendRequestAPDU(APDU&) { return CS_TIMEOUT; };
	virtual CommandStatus SendResponseAPDU(APDU&) { return CS_TIMEOUT; };
	virtual CommandStatus SendUnsolResponseAPDU(APDU&) { return CS_TIMEOUT; };


};

}
}


#endif /* APDUPROXY_H_ */
