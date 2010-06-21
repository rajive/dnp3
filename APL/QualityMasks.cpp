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
#include "QualityMasks.h"

#include <sstream>
#include <vector>


using namespace std;


#define CASE_RET(a, ret) case a: return ret
#define RET_CASE(ret, a) case a: return ret



namespace apl
{

	byte_t BinaryQualInfo::masks[] = {BQ_ONLINE, BQ_RESTART, BQ_COMM_LOST, BQ_REMOTE_FORCED_DATA, BQ_LOCAL_FORCED_DATA, BQ_CHATTER_FILTER};
	string BinaryQualInfo::names[] = {"Online", "Restart", "CommsLost", "RemoteForced", "LocalForced", "ChatterFilter"};
	char BinaryQualInfo::symbols[] = {'O', 'R', 'C', 'F', 'L', 'T'};

	byte_t AnalogQualInfo::masks[] = {AQ_ONLINE, AQ_RESTART, AQ_COMM_LOST, AQ_REMOTE_FORCED_DATA, AQ_LOCAL_FORCED_DATA, AQ_OVERRANGE, AQ_REFERENCE_CHECK};
	string AnalogQualInfo::names[] = {"Online", "Restart", "CommsLost", "RemoteForced", "LocalForced", "Overrange", "ReferenceCheck"};
	char AnalogQualInfo::symbols[] = {'O', 'R', 'C', 'F', 'L', 'V', 'K'};

	byte_t CounterQualInfo::masks[] = {CQ_ONLINE, CQ_RESTART, CQ_COMM_LOST, CQ_REMOTE_FORCED_DATA, CQ_LOCAL_FORCED_DATA, CQ_ROLLOVER, CQ_DISCONTINUITY};
	string CounterQualInfo::names[] = {"Online", "Restart", "CommsLost", "RemoteForced", "LocalForced", "Rollover", "Discontinuity"};
	char CounterQualInfo::symbols[] = {'O', 'R', 'C', 'F', 'L', 'V', 'D'};

	byte_t ControlQualInfo::masks[] = {TQ_ONLINE, TQ_RESTART, TQ_COMM_LOST, TQ_REMOTE_FORCED_DATA, TQ_LOCAL_FORCED_DATA};
	string ControlQualInfo::names[] = {"Online", "Restart", "CommsLost", "RemoteForced", "LocalForced"};
	char ControlQualInfo::symbols[] = {'O', 'R', 'C', 'F', 'L'};

	byte_t SetpointQualInfo::masks[] = {PQ_ONLINE, PQ_RESTART, PQ_COMM_LOST, PQ_REMOTE_FORCED_DATA};
	string SetpointQualInfo::names[] = {"Online", "Restart", "CommsLost", "RemoteForced"};
	char SetpointQualInfo::symbols[] = {'O', 'R', 'C', 'F'};

}
