#
# Copyright (c) 2010, 2011 Green Energy Corp.
# All rights reserved.
#

ACLOCAL_AMFLAGS = -I config/autotools/m4

SUBDIRS = src/opendnp3

CORE_BOOST_LIBS  = $(BOOST_DATE_TIME_LIB) $(BOOST_THREAD_LIB) $(BOOST_PROGRAM_OPTIONS_LIB) $(BOOST_SYSTEM_LIB)
TEST_BOOST_LIBS  = $(CORE_BOOST_LIBS) $(BOOST_UNIT_TEST_FRAMEWORK_LIB)

AM_CXXFLAGS = -Wall -I$(srcdir)/src/ $(BOOST_CPPFLAGS) -DBOOST_TEST_DYN_LINK -DBOOST_ASIO_ENABLE_CANCELIO -DBOOST_REGEX_NO_LIB
AM_LDFLAGS  = $(BOOST_LDFLAGS)

# Dummy placeholder to allow for expansion later
BUILT_SOURCES =

LIBVERSION = 0:0:0
PROJVERSION = 1.1.0

JAR_FILE = opendnp3-$(PROJVERSION).jar


apl_src = \
	src/opendnp3/APL/ASIOSerialHelpers.cpp \
	src/opendnp3/APL/AsyncLayerInterfaces.cpp \
	src/opendnp3/APL/AsyncResult.cpp \
	src/opendnp3/APL/AsyncTaskBase.cpp \
	src/opendnp3/APL/AsyncTaskContinuous.cpp \
	src/opendnp3/APL/AsyncTaskGroup.cpp \
	src/opendnp3/APL/AsyncTaskNonPeriodic.cpp \
	src/opendnp3/APL/AsyncTaskPeriodic.cpp \
	src/opendnp3/APL/AsyncTaskScheduler.cpp \
	src/opendnp3/APL/BaseDataTypes.cpp \
	src/opendnp3/APL/CommandManager.cpp \
	src/opendnp3/APL/CommandQueue.cpp \
	src/opendnp3/APL/CommandResponseQueue.cpp \
	src/opendnp3/APL/CommandTypes.cpp \
	src/opendnp3/APL/CopyableBuffer.cpp \
	src/opendnp3/APL/CRC.cpp \
	src/opendnp3/APL/EventLock.cpp \
	src/opendnp3/APL/Exception.cpp \
	src/opendnp3/APL/FlexibleDataObserver.cpp \
	src/opendnp3/APL/IHandlerAsync.cpp \
	src/opendnp3/APL/ITimerSource.cpp \
	src/opendnp3/APL/IOService.cpp \
	src/opendnp3/APL/IOServiceThread.cpp \
	src/opendnp3/APL/LockBase.cpp \
	src/opendnp3/APL/LockBoost.cpp \
	src/opendnp3/APL/Log.cpp \
	src/opendnp3/APL/LogEntryCircularBuffer.cpp \
	src/opendnp3/APL/LogEntry.cpp \
	src/opendnp3/APL/Loggable.cpp \
	src/opendnp3/APL/Logger.cpp \
	src/opendnp3/APL/LogToFile.cpp \
	src/opendnp3/APL/LogToStdio.cpp \
	src/opendnp3/APL/LogTypes.cpp \
	src/opendnp3/APL/LowerLayerToPhysAdapter.cpp \
	src/opendnp3/APL/MetricBuffer.cpp \
	src/opendnp3/APL/MultiplexingDataObserver.cpp \
	src/opendnp3/APL/PackingUnpacking.cpp \
	src/opendnp3/APL/Parsing.cpp \
	src/opendnp3/APL/PhysicalLayerAsyncBase.cpp \
	src/opendnp3/APL/PhysicalLayerAsyncBaseTCP.cpp \
	src/opendnp3/APL/PhysicalLayerAsyncSerial.cpp \
	src/opendnp3/APL/PhysicalLayerAsyncTCPClient.cpp \
	src/opendnp3/APL/PhysicalLayerAsyncTCPServer.cpp \
	src/opendnp3/APL/PhysicalLayerFactory.cpp \
	src/opendnp3/APL/PhysicalLayerInstance.cpp \
	src/opendnp3/APL/PhysicalLayerManager.cpp \
	src/opendnp3/APL/PhysicalLayerMap.cpp \
	src/opendnp3/APL/PhysicalLayerMonitor.cpp \
	src/opendnp3/APL/PhysicalLayerMonitorStates.cpp \
	src/opendnp3/APL/PhysicalLayerStates.cpp \
	src/opendnp3/APL/PhysLoopback.cpp \
	src/opendnp3/APL/PostingNotifier.cpp \
	src/opendnp3/APL/PostingNotifierSource.cpp \
	src/opendnp3/APL/ProtocolUtil.cpp \
	src/opendnp3/APL/QualityConverter.cpp \
	src/opendnp3/APL/RandomizedBuffer.cpp \
	src/opendnp3/APL/ShiftableBuffer.cpp \
	src/opendnp3/APL/SuspendTimerSource.cpp \
	src/opendnp3/APL/Threadable.cpp \
	src/opendnp3/APL/ThreadBase.cpp \
	src/opendnp3/APL/ThreadBoost.cpp \
	src/opendnp3/APL/TimeBase.cpp \
	src/opendnp3/APL/TimeBoost.cpp \
	src/opendnp3/APL/Timeout.cpp \
	src/opendnp3/APL/TimerASIO.cpp \
	src/opendnp3/APL/TimerSourceASIO.cpp \
	src/opendnp3/APL/TimeSource.cpp \
	src/opendnp3/APL/TimingTools.cpp \
	src/opendnp3/APL/ToHex.cpp \
	src/opendnp3/APL/TrackingTaskGroup.cpp \
	src/opendnp3/APL/Util.cpp


dnp3_src = \
	src/opendnp3/DNP3/AlwaysOpeningVtoRouter.cpp \
	src/opendnp3/DNP3/APDUConstants.cpp \
	src/opendnp3/DNP3/APDU.cpp \
	src/opendnp3/DNP3/AppChannelStates.cpp \
	src/opendnp3/DNP3/AppHeader.cpp \
	src/opendnp3/DNP3/AppInterfaces.cpp \
	src/opendnp3/DNP3/AppLayerChannel.cpp \
	src/opendnp3/DNP3/AppLayer.cpp \
	src/opendnp3/DNP3/AsyncStackManager.cpp \
	src/opendnp3/DNP3/BufferTypes.cpp \
	src/opendnp3/DNP3/ClassCounter.cpp \
	src/opendnp3/DNP3/ControlTasks.cpp \
	src/opendnp3/DNP3/Database.cpp \
	src/opendnp3/DNP3/DataPoll.cpp \
	src/opendnp3/DNP3/DeviceTemplate.cpp \
	src/opendnp3/DNP3/DNPCommandMaster.cpp \
	src/opendnp3/DNP3/DNPCrc.cpp \
	src/opendnp3/DNP3/EnhancedVto.cpp \
	src/opendnp3/DNP3/EnhancedVtoRouter.cpp \
	src/opendnp3/DNP3/HeaderReadIterator.cpp \
	src/opendnp3/DNP3/IndexedWriteIterator.cpp \
	src/opendnp3/DNP3/IStackObserver.cpp \
	src/opendnp3/DNP3/LinkChannel.cpp \
	src/opendnp3/DNP3/LinkFrame.cpp \
	src/opendnp3/DNP3/LinkHeader.cpp \
	src/opendnp3/DNP3/LinkLayerConstants.cpp \
	src/opendnp3/DNP3/LinkLayer.cpp \
	src/opendnp3/DNP3/LinkLayerReceiver.cpp \
	src/opendnp3/DNP3/LinkLayerRouter.cpp \
	src/opendnp3/DNP3/LinkReceiverStates.cpp \
	src/opendnp3/DNP3/LinkRoute.cpp \
	src/opendnp3/DNP3/Master.cpp \
	src/opendnp3/DNP3/MasterSchedule.cpp \
	src/opendnp3/DNP3/MasterStack.cpp \
	src/opendnp3/DNP3/MasterStates.cpp \
	src/opendnp3/DNP3/MasterTaskBase.cpp \
	src/opendnp3/DNP3/ObjectHeader.cpp \
	src/opendnp3/DNP3/ObjectInterfaces.cpp \
	src/opendnp3/DNP3/ObjectReadIterator.cpp \
	src/opendnp3/DNP3/Objects.cpp \
	src/opendnp3/DNP3/ObjectWriteIterator.cpp \
	src/opendnp3/DNP3/PointClass.cpp \
	src/opendnp3/DNP3/PriLinkLayerStates.cpp \
	src/opendnp3/DNP3/ResponseContext.cpp \
	src/opendnp3/DNP3/ResponseLoader.cpp \
	src/opendnp3/DNP3/SecLinkLayerStates.cpp \
	src/opendnp3/DNP3/SlaveConfig.cpp \
	src/opendnp3/DNP3/Slave.cpp \
	src/opendnp3/DNP3/SlaveEventBuffer.cpp \
	src/opendnp3/DNP3/SlaveResponseTypes.cpp \
	src/opendnp3/DNP3/SlaveStack.cpp \
	src/opendnp3/DNP3/SlaveStates.cpp \
	src/opendnp3/DNP3/SolicitedChannel.cpp \
	src/opendnp3/DNP3/Stack.cpp \
	src/opendnp3/DNP3/StackManager.cpp \
	src/opendnp3/DNP3/StartupTasks.cpp \
	src/opendnp3/DNP3/TLS_Base.cpp \
	src/opendnp3/DNP3/TransportLayer.cpp \
	src/opendnp3/DNP3/TransportRx.cpp \
	src/opendnp3/DNP3/TransportStates.cpp \
	src/opendnp3/DNP3/TransportTx.cpp \
	src/opendnp3/DNP3/UnsolicitedChannel.cpp \
	src/opendnp3/DNP3/VtoData.cpp \
	src/opendnp3/DNP3/VtoReader.cpp \
	src/opendnp3/DNP3/VtoRouter.cpp \
	src/opendnp3/DNP3/VtoRouterManager.cpp \
	src/opendnp3/DNP3/VtoRouterSettings.cpp \
	src/opendnp3/DNP3/VtoTransmitTask.cpp \
	src/opendnp3/DNP3/VtoWriter.cpp

apl_test_tools_src = \
	src/opendnp3/APL/test/util/AsyncPhysTestObject.cpp \
	src/opendnp3/APL/test/util/AsyncTestObjectASIO.cpp \
	src/opendnp3/APL/test/util/AsyncTestObject.cpp \
	src/opendnp3/APL/test/util/BufferHelpers.cpp \
	src/opendnp3/APL/test/util/BufferTestObject.cpp \
	src/opendnp3/APL/test/util/LogTester.cpp \
	src/opendnp3/APL/test/util/LoopbackPhysicalLayerAsync.cpp \
	src/opendnp3/APL/test/util/MockLowerLayer.cpp \
	src/opendnp3/APL/test/util/MockPhysicalLayerAsync.cpp \
	src/opendnp3/APL/test/util/MockPhysicalLayerAsyncTS.cpp \
	src/opendnp3/APL/test/util/MockPhysicalLayerMonitor.cpp \
	src/opendnp3/APL/test/util/MockPhysicalLayerSource.cpp \
	src/opendnp3/APL/test/util/MockResponseAcceptor.cpp \
	src/opendnp3/APL/test/util/MockTimerSource.cpp \
	src/opendnp3/APL/test/util/MockUpperLayer.cpp \
	src/opendnp3/APL/test/util/PhysicalLayerWrapper.cpp \
	src/opendnp3/APL/test/util/WrappedTcpPipe.cpp

apl_test_src = \
	src/opendnp3/APL/test/AsyncPhysBaseTest.cpp \
	src/opendnp3/APL/test/TestLocks.cpp \
	src/opendnp3/APL/test/TestPhysicalLayerAsyncTCP.cpp \
	src/opendnp3/APL/test/TestTime.cpp \
	src/opendnp3/APL/test/AsyncSerialTestObject.cpp \
	src/opendnp3/APL/test/TestLog.cpp \
    src/opendnp3/APL/test/TestPhysicalLayerLoopback.cpp \
	src/opendnp3/APL/test/TestTimers.cpp \
	src/opendnp3/APL/test/TestASIO.cpp \
    src/opendnp3/APL/test/TestMisc.cpp \
    src/opendnp3/APL/test/TestPhysicalLayerMonitor.cpp \
	src/opendnp3/APL/test/TestTypes.cpp \
	src/opendnp3/APL/test/TestAsyncTask.cpp \
	src/opendnp3/APL/test/TestPackingUnpacking.cpp \
	src/opendnp3/APL/test/TestQualityMasks.cpp \
	src/opendnp3/APL/test/TestUtil.cpp \
	src/opendnp3/APL/test/TestCastLongLongDouble.cpp \
	src/opendnp3/APL/test/TestParsing.cpp \
	src/opendnp3/APL/test/TestShiftableBuffer.cpp \
	src/opendnp3/APL/test/TestXmlBinding.cpp \
	src/opendnp3/APL/test/TestCommandQueue.cpp \
	src/opendnp3/APL/test/TestPhysicalLayerAsyncBase.cpp \
	src/opendnp3/APL/test/TestSyncVar.cpp \
	src/opendnp3/APL/test/TestCommandTypes.cpp \
	src/opendnp3/APL/test/TestPhysicalLayerAsyncSerial.cpp \
	src/opendnp3/APL/test/TestThreading.cpp

dnp3_test_src = \
	src/opendnp3/DNP3/test/AppLayerTest.cpp \
	src/opendnp3/DNP3/test/ComparingDataObserver.cpp \
	src/opendnp3/DNP3/test/DNPHelpers.cpp \
	src/opendnp3/DNP3/test/IntegrationTest.cpp \
	src/opendnp3/DNP3/test/LinkLayerRouterTest.cpp \
	src/opendnp3/DNP3/test/LinkLayerTest.cpp \
	src/opendnp3/DNP3/test/MasterTestObject.cpp \
	src/opendnp3/DNP3/test/MockAppLayer.cpp \
	src/opendnp3/DNP3/test/MockAppUser.cpp \
	src/opendnp3/DNP3/test/MockFrameSink.cpp \
	src/opendnp3/DNP3/test/ResponseLoaderTestObject.cpp \
	src/opendnp3/DNP3/test/SlaveTestObject.cpp \
	src/opendnp3/DNP3/test/StartupTeardownTest.cpp \
	src/opendnp3/DNP3/test/TestAPDU.cpp \
	src/opendnp3/DNP3/test/TestAPDUWriting.cpp \
	src/opendnp3/DNP3/test/TestAppLayer.cpp \
	src/opendnp3/DNP3/test/TestCRC.cpp \
	src/opendnp3/DNP3/test/TestDatabase.cpp \
	src/opendnp3/DNP3/test/TestEnhancedVtoRouter.cpp \
	src/opendnp3/DNP3/test/TestEventBufferBase.cpp \
	src/opendnp3/DNP3/test/TestEventBuffers.cpp \
	src/opendnp3/DNP3/test/TestIntegration.cpp \
	src/opendnp3/DNP3/test/TestLinkFrameDNP.cpp \
	src/opendnp3/DNP3/test/TestLinkLayer.cpp \
	src/opendnp3/DNP3/test/TestLinkLayerRouter.cpp \
	src/opendnp3/DNP3/test/TestLinkReceiver.cpp \
	src/opendnp3/DNP3/test/TestLinkRoute.cpp \
	src/opendnp3/DNP3/test/TestMaster.cpp \
	src/opendnp3/DNP3/test/TestObjects.cpp \
	src/opendnp3/DNP3/test/TestResponseLoader.cpp \
	src/opendnp3/DNP3/test/TestSlave.cpp \
	src/opendnp3/DNP3/test/TestSlaveEventBuffer.cpp \
	src/opendnp3/DNP3/test/TestStartBoostUTF.cpp \
	src/opendnp3/DNP3/test/TestStartupTeardown.cpp \
	src/opendnp3/DNP3/test/TestTransportLayer.cpp \
	src/opendnp3/DNP3/test/TestTransportLoopback.cpp \
	src/opendnp3/DNP3/test/TestTransportScalability.cpp \
	src/opendnp3/DNP3/test/TestVtoInterface.cpp \
	src/opendnp3/DNP3/test/TestVtoLoopbackIntegration.cpp \
	src/opendnp3/DNP3/test/TestVtoOnewayIntegration.cpp \
	src/opendnp3/DNP3/test/TestVtoRouter.cpp \
	src/opendnp3/DNP3/test/TestVtoRouterManager.cpp \
	src/opendnp3/DNP3/test/TestVtoWriter.cpp \
	src/opendnp3/DNP3/test/TransportIntegrationStack.cpp \
	src/opendnp3/DNP3/test/TransportLoopbackTestObject.cpp \
	src/opendnp3/DNP3/test/TransportScalabilityTestObject.cpp \
	src/opendnp3/DNP3/test/TransportStackPair.cpp \
	src/opendnp3/DNP3/test/TransportTestObject.cpp \
	src/opendnp3/DNP3/test/VtoIntegrationTestBase.cpp

apl_xml_src = \
	src/opendnp3/xml/APL/PhysicalLayerManagerXML.cpp \
	src/opendnp3/xml/APL/PhysicalLayerXMLFactory.cpp \
	src/opendnp3/xml/APL/tinybinding.cpp \
	src/opendnp3/xml/APL/XML_APL.cpp \
	src/opendnp3/xml/APL/XMLConversion.cpp

dnp3_xml_src = \
	src/opendnp3/xml/DNP3/XML_DNP3.cpp \
	src/opendnp3/xml/DNP3/XML_TestSet.cpp \
	src/opendnp3/xml/DNP3/XmlToConfig.cpp

xml_binding_src = \
	src/opendnp3/xml/binding/APLXML_Base.cpp \
	src/opendnp3/xml/binding/APLXML_DNP.cpp \
	src/opendnp3/xml/binding/APLXML_MTS.cpp \
	src/opendnp3/xml/binding/APLXML_STS.cpp

tinyxml_src = \
	src/tinyxml/tinyxml.cpp \
	src/tinyxml/tinyxmlerror.cpp \
	src/tinyxml/tinyxmlparser.cpp

terminal_src = \
	src/opendnp3/terminal/ControlResponseTE.cpp \
	src/opendnp3/terminal/ControlTerminalExtension.cpp \
	src/opendnp3/terminal/DOTerminalExtension.cpp \
	src/opendnp3/terminal/FlexibleObserverTerminalExtension.cpp \
	src/opendnp3/terminal/LineReader.cpp \
	src/opendnp3/terminal/LogTerminalExtension.cpp \
	src/opendnp3/terminal/PhysicalLayerIOStreamAsync.cpp \
	src/opendnp3/terminal/PhysicalLayerSyncProxy.cpp \
	src/opendnp3/terminal/Terminal.cpp \
	src/opendnp3/terminal/TerminalInterfaces.cpp

terminal_test_src = \
	src/opendnp3/terminal/test/TestPhysicalLayerSyncProxy.cpp \
	src/opendnp3/terminal/test/TestTerminal.cpp

	
testset_src = \
	src/opendnp3/testset/AddressScanner.cpp \
	src/opendnp3/testset/main.cpp \
	src/opendnp3/testset/StackHelpers.cpp

demo_master_src = \
	demos/master-cpp/DemoMain.cpp \
	demos/master-cpp/MasterDemo.cpp

demo_slave_src = \
	demos/slave-cpp/DemoMain.cpp \
	demos/slave-cpp/SlaveDemo.cpp


teamcity_src = \
	teamcity/teamcity_boost.cpp \
	teamcity/teamcity_messages.cpp


#
# Main shared library
#

lib_LTLIBRARIES = libopendnp3.la

libopendnp3_la_LDFLAGS = -version-info $(LIBVERSION)
libopendnp3_la_LIBADD = $(BOOST_LDFLAGS) $(CORE_BOOST_LIBS)
libopendnp3_la_DEPENDENCIES =
libopendnp3_la_SOURCES = \
	$(apl_src) \
	$(dnp3_src)


#
# Convenience libraries
#

noinst_LIBRARIES = libapltesttools.a libxmlbindings.a libaplxml.a libdnp3xml.a libterminal.a libteamcity.a

libapltesttools_a_SOURCES = \
	$(apl_test_tools_src)

libxmlbindings_a_SOURCES = \
	$(xml_binding_src) \
	$(tinyxml_src)

libaplxml_a_SOURCES = \
	$(apl_xml_src)

libdnp3xml_a_SOURCES = \
	$(dnp3_xml_src)	

libterminal_a_SOURCES = \
	$(terminal_src)	

libteamcity_a_SOURCES = \
	$(teamcity_src)	

#
# Installed programs
#

bin_PROGRAMS = dnp3testset

dnp3testset_LDADD = libxmlbindings.a  libdnp3xml.a libaplxml.a libterminal.a libopendnp3.la $(CORE_BOOST_LIBS)
dnp3testset_CFLAGS = -Itinyxml
dnp3testset_SOURCES = \
	$(testset_src) 

#
# Uninstalled programs (tests / demos)
#

noinst_PROGRAMS = test-apl test-dnp3 test-terminal demo-master-cpp demo-slave-cpp

# must be linked before boost test
if TEAMCITY
teamcitylib=libteamcity.a
else 
teamcitylib=
endif

test_apl_LDADD = libapltesttools.a libxmlbindings.a libaplxml.a $(teamcitylib) libopendnp3.la $(TEST_BOOST_LIBS)
test_apl_SOURCES = \
	$(apl_test_src)

test_dnp3_LDADD = libapltesttools.a libopendnp3.la $(TEST_BOOST_LIBS)
test_dnp3_SOURCES = \
	$(dnp3_test_src)

test_terminal_LDADD = libapltesttools.a libterminal.a libopendnp3.la $(TEST_BOOST_LIBS)
test_terminal_SOURCES = \
	$(terminal_test_src)

demo_master_cpp_LDADD = libopendnp3.la $(CORE_BOOST_LIBS)
demo_master_cpp_SOURCES = \
	$(demo_master_src)

demo_slave_cpp_LDADD = libopendnp3.la $(CORE_BOOST_LIBS)
demo_slave_cpp_SOURCES = \
	$(demo_slave_src)


#
# SWIG
# 

JAVA_DIR=$(builddir)/maven

if WANT_JAVA
JAVA_PACKAGE_DIR=org/totalgrid/dnp3
JAVA_SOURCE_DIR=$(JAVA_DIR)/src/main/java/
JAVA_CLASS_DIR=$(JAVA_DIR)/bin

JAVA_SRC_FILES = $(JAVA_SOURCE_DIR)/$(JAVA_PACKAGE_DIR)/*.java

swig/.java-built: swig/swigDNP3.i
	-@mkdir -p $(JAVA_SOURCE_DIR)/$(JAVA_PACKAGE_DIR)
	swig -c++ -java \
		-package org.totalgrid.dnp3 \
		-I$(top_srcdir)/src \
		-outdir $(JAVA_SOURCE_DIR)/$(JAVA_PACKAGE_DIR) \
		-o swig/JavaDNP3.cpp $^
	cp -R $(srcdir)/java/pom.xml $(JAVA_DIR)
	cp -R $(srcdir)/java/src $(JAVA_DIR)
	touch $@

swig/JavaDNP3.cpp: swig/.java-built
$(JAVA_SRC_FILES): swig/.java-built

BUILT_SOURCES += swig/.java-built swig/JavaDNP3.cpp $(JAVA_SRC_FILES)

lib_LTLIBRARIES += libopendnp3-java.la
libopendnp3_java_la_SOURCES = swig/JavaDNP3.cpp
libopendnp3_java_la_CPPFLAGS = 
libopendnp3_java_la_LDFLAGS = -version-info $(LIBVERSION)
libopendnp3_java_la_LIBADD = libopendnp3.la

endif

if WANT_PYTHON
pkgpython_PYTHON = pyopendnp3.py __init__.py
pkgpyexec_LTLIBRARIES = _pyopendnp3.la
_pyopendnp3_la_SOURCES = swig/PythonDNP3.cpp
_pyopendnp3_la_CPPFLAGS = $(SWIG_PYTHON_CPPFLAGS) $(PYTHON_CPPFLAGS)
_pyopendnp3_la_LDFLAGS = -module $(PYTHON_LDFLAGS)
_pyopendnp3_la_LIBADD = libopendnp3.la

__init__.py:
	echo "from pyopendnp3 import *" > $@

swig/PythonDNP3.cpp: swig/swigDNP3.i
	swig -c++ -python \
		-threads \
		-module pyopendnp3 \
		-I$(top_srcdir)/src \
		-outdir . \
		-o swig/PythonDNP3.cpp $^

BUILT_SOURCES += swig/PythonDNP3.cpp
endif


ASTYLE=astyle --options=${srcdir}/config/astyle.cfg

DOCBOOK2HTML=docbook2html
DOCBOOK2PDF=docbook2pdf

astyle:
	${ASTYLE}   ${srcdir}/src/opendnp3/APL/*.cpp            	${srcdir}/src/opendnp3/APL/*.h
	${ASTYLE}   ${srcdir}/src/opendnp3/APL/test/*.cpp           ${srcdir}/src/opendnp3/APL/test/*.h
	${ASTYLE}   ${srcdir}/src/opendnp3/APL/test/util/*.cpp   	${srcdir}/src/opendnp3/APL/test/util/*.h
	${ASTYLE}   ${srcdir}/src/opendnp3/DNP3/*.cpp           	${srcdir}/src/opendnp3/DNP3/*.h
	${ASTYLE}   ${srcdir}/src/opendnp3/DNP3/test/*.cpp       	${srcdir}/src/opendnp3/DNP3/test/*.h
	${ASTYLE}   ${srcdir}/src/opendnp3/terminal/*.cpp           ${srcdir}/src/opendnp3/terminal/*.h
	${ASTYLE}   ${srcdir}/src/opendnp3/terminal/test/*.cpp      #${srcdir}/src/opendnp3/terminal/test/*.h
	${ASTYLE}   ${srcdir}/src/opendnp3/testset/*.cpp           	${srcdir}/src/opendnp3/testset/*.h
	${ASTYLE}   ${srcdir}/src/opendnp3/xml/APL/*.cpp           	${srcdir}/src/opendnp3/xml/APL/*.h
	${ASTYLE}   ${srcdir}/src/opendnp3/xml/DNP3/*.cpp           ${srcdir}/src/opendnp3/xml/DNP3/*.h

docs: docs-html docs-pdf

docs-html:
	-@mkdir -p docs/html/
	${DOCBOOK2HTML} -o docs/html/ ${srcdir}/docs/main.xml

docs-pdf:
	-@mkdir -p docs/pdf/
	${DOCBOOK2PDF} -o docs/pdf/ ${srcdir}/docs/main.xml

include config/autotools/mk/doxygen.mak
include config/autotools/mk/lcov.mak

clean-swig:
	-rm -rf swig/JavaDNP3.cpp swig/JavaDNP3.h swig/.java-built
	-rm -rf swig/PythonDNP3.cpp swig/PythonDNP3.h
	-rm -rf pyopendnp3.py pyopendnp3.pyc __init__.py
	-rm -rf $(JAVA_DIR)
	-rm -rf $(JAR_FILE)

clean-local: clean-swig clean-lcov

.PHONY : astyle docs docs-html docs-pdf lcov lcov-report lcov-reset doxygen-run doxygen-doc $(DX_PS_GOAL) $(DX_PDF_GOAL)

