#include "stdafx.h"
#include "Stubs.h"

static string chTag;
static string chTagC;
static string chId;

void create_childs(unsigned int aNumberOfChilds, Node * aRoot)
{
	// Check root exists
	CPPUNIT_ASSERT(aRoot != nullptr);
	// get child list for checking size
	vector<Node*>* childList = aRoot->get_childList();

	for (unsigned int i = 0; i < aNumberOfChilds; i++)
	{
		auto theTag = construct_child_Tag(&i);
		auto theTagC = construct_child_TagC(&i);
		auto theId = construct_child_Id(&i);
		new Node(aRoot, &theTag, &theTagC, &theId, 0);
	}

	CPPUNIT_ASSERT_EQUAL(childList->size(), aNumberOfChilds);
}

string construct_child_Tag(unsigned int* aCaunter)
{
	return	"<child" + to_string(*aCaunter) + ">";
}

string construct_child_TagC(unsigned int* aCaunter)
{
	return "for child<" + to_string(*aCaunter) + ">";
}

string construct_child_Id(unsigned int* aCaunter)
{
	return "root.child" + to_string(*aCaunter);
}

void Tree_create_childs(Tree * aTree, unsigned int aNumberOfLevels)
{
	CPPUNIT_ASSERT(aTree != nullptr);
	auto theRoot = aTree->get_root_Tr();
	auto theRootId = theRoot->get_id();
	auto theLevel = theRoot->get_level();
	unsigned int tagsOnLevel = 5;
	CPPUNIT_ASSERT(theLevel == 0);
	string aTag = "<a>";
	string aTagC = "<a content>";
	string newRootId;
	string baseRoot;
	auto theLevels = aTree->get_level_container_Tr();
	auto lvlIt = aTree->get_level_container_Tr()->begin();

	for (unsigned int counter = 0; counter < aNumberOfLevels; counter++)
	{
		auto lvlIt = aTree->get_level_container_Tr()->at(counter);

		for (auto insideLvlIter = lvlIt.begin(); insideLvlIter != lvlIt.end(); insideLvlIter++)
		{

			for (unsigned int cPerLvl = 0; cPerLvl < tagsOnLevel; cPerLvl++)
			{
				aTree->add_node_Tr(*insideLvlIter, &aTag, &aTagC);
			}
		}
	}
	//aTree->print_tree_Tr();
}
