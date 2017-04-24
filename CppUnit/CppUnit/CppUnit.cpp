// CppUnit.cpp: main application file
// Dont forget point CppUnit project as autoloaded loaded 

#include "stdafx.h"
#include <cppunit/ui/text/TestRunner.h>

CPPUNIT_TEST_SUITE_REGISTRATION(Node_test);

int main()
{
	CppUnit::TextUi::TestRunner runner;
	CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
	runner.addTest(registry.makeTest());
	runner.run();
	return 0;

}

