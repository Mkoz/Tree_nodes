#pragma once

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class Node_test :public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(Node_test);
	CPPUNIT_TEST(myTest1);
	CPPUNIT_TEST(myTest2);
	CPPUNIT_TEST_SUITE_END();
public:
	Node_test();
	~Node_test();
	void setUp();
	void tearDown();
	void myTest1();
	void myTest2();
};
