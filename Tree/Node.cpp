#include "stdafx.h"
#include "Node.h"

Node::Node(Node* aRoot, string* aTag, string* aTagContent, string* anId) : root_Node(aRoot), tag_Node(*aTag), tagContent_Node(*aTagContent), id_Node(*anId)
{
	PRINT << "Constructor for tag: " << this->get_tag() << endl;
	childList_Node = vector<Node*>();
}

Node::~Node()
{
}

void Node::addChild(Node * aChild)
{
	childList_Node.push_back(aChild);
}

void Node::print_child()
{
	for (auto it = childList_Node.begin(); it != childList_Node.end(); it++)
	{
		PRINT << this->get_id() << " - Child: " << *it << " + " << ((Node*)*it)->get_id() << endl;
	}
}
