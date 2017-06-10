// Tree_test.h: Interface for Tree_test class
#pragma once
#include "stdafx.h"
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class Tree_test :public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(Tree_test);
	CPPUNIT_TEST(checkRoot);
	CPPUNIT_TEST(create_a_lot_of_childs_with_the_same_tag);
	CPPUNIT_TEST(create_second_root);
	CPPUNIT_TEST(remove_root);
	CPPUNIT_TEST(remove_childs);
	CPPUNIT_TEST_SUITE_END();
public:
	Tree_test();
	~Tree_test();
	void setUp();
	void tearDown();

	// Test declarations
	// Normal cases
	void checkRoot();
	void create_a_lot_of_childs_with_the_same_tag();
	void remove_root();
	void remove_childs();

	//Erro cases
	void create_second_root();
	void remove_not_existed_node();

	// it has not sence make these vars protected, it just test framework
	// It should nit be published anythere
	string chTag;
	string chTagC;
	string chId;
	string rootTag;
	string rootTagC;
	string rootId;

private:
	Tree* create_Tree_with_root();

};
