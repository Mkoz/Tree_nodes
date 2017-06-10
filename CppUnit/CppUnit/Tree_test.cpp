// Tree_test.cpp: Main test class realization
#include "stdafx.h"
#include "Tree_test.h"
/*static string chTag;
static string chTagC;
static string chId; // Should not be used for Tree, saved for backward compatiblity
*/
Tree_test::Tree_test() : rootTag("<root>"), rootTagC("Content for root"), rootId("root")
{
}

Tree_test::~Tree_test()
{
}

void Tree_test::setUp()
{
}

void Tree_test::tearDown()
{
}
void Tree_test::checkRoot()
{
	Tree* testRoot = create_Tree_with_root();
}

void Tree_test::create_a_lot_of_childs_with_the_same_tag()
{
	Tree* testRoot = create_Tree_with_root();
	auto numberOfLevels = 4;

	Tree_create_childs(testRoot, numberOfLevels);

	CPPUNIT_ASSERT(numberOfLevels+1 == testRoot->get_level_container_Tr()->size());
	// Check what all ids are uniq
	for (auto iter = testRoot->get_level_container_Tr()->begin(); iter != testRoot->get_level_container_Tr()->end(); iter++)
	{
		for (auto iterIter = iter->begin(); iterIter != iter->end(); iterIter++)
		{
			for (auto iter2 = testRoot->get_level_container_Tr()->begin(); iter2 != testRoot->get_level_container_Tr()->end(); iter2++)
			{
				for (auto iterIter2 = iter2->begin(); iterIter2 != iter2->end(); iterIter2++)
				{
					if (*iterIter != *iterIter2)
					{
						if ((*iterIter)->get_id() == (*iterIter2)->get_id())
						{
							CPPUNIT_FAIL("There are two identical id");
						}

					}
				}
			}
		}
	}
	//testRoot->print_tree_Tr();
}

void Tree_test::remove_root()
{
	Tree* testRoot = create_Tree_with_root();
	CPPUNIT_ASSERT(testRoot->remove_node_Tr(testRoot->get_root_Tr()));
	CPPUNIT_ASSERT(testRoot->get_level_container_Tr()->size() == 0);
}

void Tree_test::remove_childs()
{
	Tree* testRoot = create_Tree_with_root();

	Tree_create_childs(testRoot, 3);

	while (testRoot->get_level_container_Tr()->size())
	{
		auto initialSize = testRoot->get_level_container_Tr()->size();
		auto theLevel = testRoot->get_level_container_Tr()->rbegin();
		while (initialSize == testRoot->get_level_container_Tr()->size())
		{
			auto theLastNode = theLevel->rbegin();
			//PRINT << "Level size: " << theLevel->size() << endl;
			CPPUNIT_ASSERT(testRoot->remove_node_Tr(*theLastNode));

		}
	}
	CPPUNIT_ASSERT(testRoot->get_level_container_Tr()->size() == 0);

}

void Tree_test::create_second_root()
{
	Tree* testRoot = create_Tree_with_root();

	CPPUNIT_ASSERT(testRoot->add_node_Tr(nullptr, &rootTag, &rootTagC) == false);
}

Tree* Tree_test::create_Tree_with_root()
{
	Tree* testRoot = new Tree();
	testRoot->add_node_Tr(nullptr, &rootTag, &rootTagC);
	CPPUNIT_ASSERT(testRoot->get_node_by_id_Tr(&rootId));
	CPPUNIT_ASSERT_EQUAL(testRoot->get_node_by_id_Tr(&rootId)->get_id(), rootId);
	CPPUNIT_ASSERT_EQUAL(testRoot->get_node_by_id_Tr(&rootId)->get_tag(), rootTag);
	CPPUNIT_ASSERT_EQUAL(testRoot->get_node_by_id_Tr(&rootId)->get_tagContent(), rootTagC);
	CPPUNIT_ASSERT(testRoot->get_node_by_id_Tr(&rootId)->get_root() == nullptr);
	return testRoot;
}




