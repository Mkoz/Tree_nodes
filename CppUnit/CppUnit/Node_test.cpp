// Node_test.cpp: Main test class realization
#include "stdafx.h"
#include "Node_test.h"
extern string chTag;
extern string chTagC;
//extern string chId;

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
	create_childs(10, testRoot);

	auto childList = testRoot->get_childList();
	auto childIter = childList->begin();
	for (unsigned int childListSize = 0; childListSize < childList->size(); childListSize++, childIter++)
	{
		CPPUNIT_ASSERT_EQUAL(((Node*)(*childIter))->get_id(), construct_child_Id(&childListSize));
		CPPUNIT_ASSERT_EQUAL(((Node*)(*childIter))->get_tag(), construct_child_Tag(&childListSize));
		CPPUNIT_ASSERT_EQUAL(((Node*)(*childIter))->get_tagContent(), construct_child_TagC(&childListSize));
		CPPUNIT_ASSERT(((Node*)(*childIter))->get_root() != nullptr);
	}

}

