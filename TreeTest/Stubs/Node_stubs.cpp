#include "../stdafx.h"
#include "Node_stubs.h"


Node * CREATE_ROOT()
{
	string rootTag = "<root>";
	string rootTagC = "for root";
	string rootId = "root";
	Node* testNode = new Node(NULL, &rootTag, &rootTagC, &rootId);;

	// Check what node have been created
	Assert::IsNotNull(testNode);

	return testNode;
}

Node * CREATE_CHILDS(unsigned int aNumberOfChilds, Node * aRoot)
{
	// Check root exists
	Assert::IsNotNull(aRoot);

	string chTag;
	string chTagC;
	string chId;
	vector<Node*>* childList = aRoot->get_childList();

	for (unsigned int i = 0; i < aNumberOfChilds; i++)
	{
		chTag = "<child" + to_string(i) + ">";
		chTagC = "for child<" + to_string(i) + ">";
		chId = "root.child" + to_string(i);
		aRoot->add_child(new Node(aRoot, &chTag, &chTagC, &chId));

		Assert::AreEqual(childList->size(), i+1);

	}
	return nullptr;
}
