// Node_test.h: Interface for Node_test class
#pragma once
#include "stdafx.h"
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>


class Node_test :public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(Node_test);
	CPPUNIT_TEST(checkRoot);
	CPPUNIT_TEST(checkChilds);
	CPPUNIT_TEST_SUITE_END();
public:
	Node_test();
	~Node_test();
	void setUp();
	void tearDown();

// Test declarations
	void checkRoot();
	void checkChilds();

// Service section



// it has not sence make these vars protected, it just test framework
// It should nit be published anythere
	string chTag;
	string chTagC;
	string chId;
	string rootTag;
	string rootTagC;
	string rootId;

};
