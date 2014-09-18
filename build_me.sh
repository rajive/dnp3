#!/bin/bash
# Copyright 2014 Real-Time Innovations, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

TOOLS_HOME=$(cd $(dirname "$0"); cd ../; pwd -P)/dnp3-tools
echo TOOLS_HOME=$TOOLS_HOME
export TOOLS_HOME

# Create dnp3-tools/ as a peer of dnp3/
cd ${TOOLS_HOME}/..
pwd
./dnp3/tools/install_scripts/boost/1_47_0/install-boost.sh

# Build dnp3
cd dnp3
pwd
rake debug=true

if [[ $? -eq 0 ]]
then 
	rm -rf ../temp
fi
