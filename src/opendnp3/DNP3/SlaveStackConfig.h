//
// Licensed to Green Energy Corp (www.greenenergycorp.com) under one
// or more contributor license agreements. See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  Green Enery Corp licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.
//
#ifndef __SLAVE_STACK_CONFIG_H_
#define __SLAVE_STACK_CONFIG_H_

#include "SlaveConfig.h"
#include "DeviceTemplate.h"
#include "AppConfig.h"
#include "LinkConfig.h"
#include "VtoConfig.h"

namespace apl
{
namespace dnp
{

/** A composite configuration struct that contains all the config
	information for a dnp3 slave stack
*/
struct SlaveStackConfig {
	SlaveStackConfig() :
		link(false, false)
	{}

	SlaveConfig slave;		// Slave config
	DeviceTemplate device;	// Device template that specifies database layout, control behavior
	AppConfig app;			// Application layer config
	LinkConfig link;		// Link layer config
	VtoConfig vto;
};

}
}

#endif
