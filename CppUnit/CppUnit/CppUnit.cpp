// CppUnit.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <cppunit/ui/text/TestRunner.h>
#include "Node_test.h"


CPPUNIT_TEST_SUITE_REGISTRATION(Node_test);

int main()
{
	std::cout << "aaaaaaaaaaaaaaa" << std::endl;

	CppUnit::TextUi::TestRunner runner;
	CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
	runner.addTest(registry.makeTest());
	runner.run();
	return 0;

}

