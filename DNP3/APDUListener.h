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
 * APDUListener.h
 *
 *  Created on: Jul 24, 2012
 *      Author: asorbini
 */

#ifndef APDULISTENER_H_
#define APDULISTENER_H_

#include "APDU.h"

namespace apl {

namespace dnp {

class APDUProxy;

class APDUFilter {
public:
	virtual ~APDUFilter() {
	}
	;
	virtual bool filter(
			const APDU&) {
		return false;
	}
	;
};

class APDUListener {
public:
	APDUListener() :
			defaultName("APDUListener") {
	}
	;
	virtual ~APDUListener() {
	}
	;
	virtual std::string& getName() {
		return defaultName;
	}
	;
	virtual void newRequestAPDU(
			APDUProxy*, APDU&) {
	}
	;
	virtual void newResponseAPDU(
			APDUProxy*, APDU&) {
	}
	;
	virtual void newUnsolResponseAPDU(
			APDUProxy*, APDU&) {
	}
	;

	friend bool operator<(
			APDUListener l1, APDUListener l2) {
		return l1.getName() < l2.getName();
	}

private:
	std::string defaultName;
};

}
}

#endif /* APDULISTENER_H_ */
