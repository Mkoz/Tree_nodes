#pragma once
#include <string>
#include <vector>
#include "stdafx.h"

class Node
{
public:
	Node( Node* aRoot, string* aTag, string* aTagContent, string* anId);
	~Node();

// Inlile getters to speed up module a bit
	inline Node* get_root() { return this->root_Node; };
	inline string get_tag() { return this->tag_Node; };
	inline string get_tagContent() { return this->tagContent_Node; };
	inline string get_id() { return this->id_Node; };
	inline vector<Node*>::iterator get_childList() { return this->childList_Node.begin(); };

	void add_child(Node* aChild);

// Print functions
	void print_child();
	void print_node();


protected:
	Node* root_Node;
	string tag_Node;
	string tagContent_Node;
	string id_Node;
	vector<Node*> childList_Node;
};

