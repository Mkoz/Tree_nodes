// Node.h: Interface for Node class
#pragma once
#include <string>
#include <vector>
#include "stdafx.h"

class Node
{
public:
	Node( Node* aRoot, string* aTag, string* aTagContent, string* anId, unsigned int aLevel);
	~Node();

// Inlile getters to speed up the module a bit
	inline Node* get_root() { return this->root_Node; };
	inline string get_tag() { return this->tag_Node; };
	inline string get_tagContent() { return this->tagContent_Node; };
	inline string get_id() { return this->id_Node; };
	inline unsigned int get_level() { return this->level_Node; };
	inline vector<Node*>* get_childList() { return &(this->childList_Node); };



// Print definitions
	void print_child();
	void print_node();


protected:
// Attributes
	Node* root_Node;
	string tag_Node;
	string tagContent_Node;
	string id_Node;
	vector<Node*> childList_Node;

	void add_child(Node* aChild);
	unsigned int level_Node;
};

	struct childs_Node {
		int child_level;
		int child_position;
	};

