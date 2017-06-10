// Node.cpp: Main test class realization
#include "stdafx.h"
#include "Node.h"

Node::Node(Node* aRoot, string* aTag, string* aTagContent, string* anId, unsigned int aLevel) : root_Node(aRoot), tag_Node(*aTag), tagContent_Node(*aTagContent), id_Node(*anId), level_Node(aLevel)
{
	//PRINT << "Constructor for tag: " << this->get_tag() << endl;
	childList_Node = vector<Node*>();
	if (aRoot != nullptr)
	{
		aRoot->add_child(this);
	}
}

Node::~Node()
{
	//PRINT << "Destructor for tag: " << this->get_tag() << " : " << this<< endl;
}

void Node::add_child(Node * aChild)
{
	childList_Node.push_back(aChild);
}

void Node::print_child()
{
	for (auto it = childList_Node.begin(); it != childList_Node.end(); it++)
	{
		PRINT << this->get_id() << " - Child: " << *it << endl;
	}
}

void Node::print_node()
{
	PRINT << "#################### " << this->get_id() << " ####################" << endl;
	PRINT << "TAG: " << this->get_tag() << "; Tag content: " << this->get_tagContent() << ";" << endl;
	this->print_child();
	PRINT << "########################################" << endl;
}
