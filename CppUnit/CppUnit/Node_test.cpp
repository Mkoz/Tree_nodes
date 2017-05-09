// Node_test.cpp: Main test class realization
#include "stdafx.h"
#include "Node_test.h"

Node_test::Node_test() : rootTag("<root>"), rootTagC("Content for root"), rootId("root")
{
}


Node_test::~Node_test()
{
}

void Node_test::setUp()
{
}

void Node_test::tearDown()
{
}

void Node_test::checkRoot()
{
	Node* testRoot = new Node(NULL, &rootTag, &rootTagC, &rootId, 0);

	CPPUNIT_ASSERT_EQUAL(testRoot->get_id(), templ_rootId);
	CPPUNIT_ASSERT_EQUAL(testRoot->get_tag(), templ_rootTag);
	CPPUNIT_ASSERT_EQUAL(testRoot->get_tagContent(), templ_rootTagC);
	CPPUNIT_ASSERT(testRoot->get_root() == nullptr);
}

void Node_test::checkChilds()
{
	Node* testRoot = new Node(NULL, &rootTag, &rootTagC, &rootId, 0);
	create_childs(1000, testRoot);

	auto childList = testRoot->get_childList();
	auto childIter = childList->begin();
	for (unsigned int childListSize = 0; childListSize < childList->size(); childListSize++, childIter++, &chTag, &chTagC, &chId)
	{
		construct_child(&childListSize);
		CPPUNIT_ASSERT_EQUAL(((Node*)(*childIter))->get_id(), chId);
		CPPUNIT_ASSERT_EQUAL(((Node*)(*childIter))->get_tag(), chTag);
		CPPUNIT_ASSERT_EQUAL(((Node*)(*childIter))->get_tagContent(), chTagC);
		CPPUNIT_ASSERT(((Node*)(*childIter))->get_root() != nullptr);
	}

}

