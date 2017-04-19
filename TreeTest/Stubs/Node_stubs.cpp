#include "../stdafx.h"
#include "Node_stubs.h"


Node * CREATE_ROOT()
{
	Node* testNode = new Node(NULL, &rootTag, &rootTagC, &rootId);;

	// Check what node have been created
	Assert::IsNotNull(testNode);

	return testNode;
}

Node * CREATE_CHILDS(unsigned int aNumberOfChilds, Node * aRoot)
{
	// Check root exists
	Assert::IsNotNull(aRoot);


	vector<Node*>* childList = aRoot->get_childList();

	for (unsigned int i = 0; i < aNumberOfChilds; i++)
	{
		construct_child(&i);
		aRoot->add_child(new Node(aRoot, &chTag, &chTagC, &chId));

		Assert::AreEqual(childList->size(), i+1);

	}
	return nullptr;
}

void CHECK_ROOT(Node* aNode)
{
	Assert::AreEqual(aNode->get_id().c_str(), rootId.c_str());
	Assert::AreEqual(aNode->get_tag().c_str(), rootTag.c_str());
	Assert::AreEqual(aNode->get_tagContent().c_str(), rootTagC.c_str());
	Assert::IsNull(aNode->get_root());

}

void CHECK_CHILDS(Node* aNode)
{
	auto childList = aNode->get_childList();
	auto childIter = childList->begin();
	//TEST_PRINT << "Child size = " << childSize;
	for (unsigned int childListSize = 0; childListSize < childList->size() ; childListSize ++, childIter ++)
	{
		construct_child(&childListSize);
		Assert::AreEqual(((Node*)(*childIter))->get_id().c_str(), chId.c_str());
		Assert::AreEqual(((Node*)(*childIter))->get_tag().c_str(), chTag.c_str());
		Assert::AreEqual(((Node*)(*childIter))->get_tagContent().c_str(), chTagC.c_str());
		Assert::IsNotNull(((Node*)(*childIter))->get_root());
	}
}
void construct_child(unsigned int * aCaunter)
{
	chTag = "<child" + to_string(*aCaunter) + ">";
	chTagC = "for child<" + to_string(*aCaunter) + ">";
	chId = "root.child" + to_string(*aCaunter);
}
