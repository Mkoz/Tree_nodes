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
