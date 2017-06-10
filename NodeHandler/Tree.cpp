// NodeHandler.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Tree.h"

using namespace std;
Tree::Tree():level_container_Tr(NULL)
{
}

Tree::~Tree()
{
	if (level_container_Tr.size() > 0)
	{
		for (auto iter = level_container_Tr.begin(); iter != level_container_Tr.end(); iter++)
		{
			for (auto itForRemoval = iter->begin(); itForRemoval != iter->end(); itForRemoval++)
			{
				delete *itForRemoval;
			}
		}
	}
}

bool Tree::add_node_Tr(Node* aRoot,string *aTag, string *aTagC)
{
	auto levelSize = level_container_Tr.size();
	string id;
	if ( levelSize == 0 )
	{

		level_container_Tr.push_back(vector<Node*>());
		id = create_id_Tr(nullptr, *aTag);
		level_container_Tr[0].push_back(new Node(nullptr, aTag, aTagC, &id, 0));
	} else {
		if ( aRoot == nullptr)
		{
			PRINT_ERROR << "Root already exists, Node* must be pointed as a root" << endl;
			return false;
		}
		auto rootLevel = aRoot->get_level();
		auto delta = levelSize - rootLevel;
		if ( delta > 2)
		{
			return false;
		}
		if (delta == 1)
		{
			level_container_Tr.push_back(vector<Node*>());
		}
		id = create_id_Tr(aRoot, *aTag);
		level_container_Tr[rootLevel + 1].push_back(new Node(aRoot, aTag, aTagC, &id, rootLevel+1 ));
	}

	return true;
}

Node * Tree::get_node_by_id_Tr(string* anId)
{
	unsigned int counter = 0;
	for (vector<vector<Node*>>::iterator it = level_container_Tr.begin(); it != level_container_Tr.end(); it++, counter++)
	{
		for (auto iter = level_container_Tr[counter].begin(); iter != level_container_Tr[counter].end(); iter++)
		{
			if ((*iter)->get_id() == *anId)
			{
				return *iter;
			}
		}
	}
	return nullptr;
}

void Tree::print_tree_Tr()
{
	unsigned int counter = 0;
	for (vector<vector<Node*>>::iterator it = level_container_Tr.begin(); it != level_container_Tr.end(); it++, counter++ )
	{
		PRINT << "================ LEVEL " << counter << "=====================" << endl;
		for (auto iter = level_container_Tr[counter].begin(); iter != level_container_Tr[counter].end(); iter++)
		{
			(*iter)->print_node();
		}
	}
}

string Tree::create_id_Tr(Node* aRoot, string aTag)
{
// Id looks like root.tag<number of repeats on level>.tag<number of repeats on level>

	string theId;
	if (aRoot == nullptr)
	{
		remove_symbol(&aTag, "<");
		remove_symbol(&aTag, ">");
		theId = aTag;
		return theId;
	}

	unsigned int numberOfRepeats = 0;

	for (auto iter = aRoot->get_childList()->begin(); iter != aRoot->get_childList()->end(); iter++)
	{
		if (aTag == (*iter)->get_tag())
		{
			numberOfRepeats++;
		}
	}

	remove_symbol(&aTag, "<");
	remove_symbol(&aTag, ">");
	theId = aRoot->get_id() + "." + aTag + to_string(numberOfRepeats);

	return theId;
}

void Tree::remove_symbol(string * aTag, string aSymbol)
{
	auto position = aTag->find(aSymbol);

	if (position != string::npos)
	{
		aTag->erase(position, 1);
	}
}

bool Tree::remove_node_Tr(Node* aNode)
{
	auto theLevel = aNode->get_level();
	for (auto iter = level_container_Tr.at(theLevel).begin(); iter != level_container_Tr.at(theLevel).end(); iter++)
	{
		if (aNode->get_id() == (*iter)->get_id())
		{
			level_container_Tr.at(theLevel).erase(iter);
			//PRINT << "Remove: " << level_container_Tr.at(theLevel).size() << endl;
			delete aNode;
			if (level_container_Tr.at(theLevel).size() == 0)
			{
				level_container_Tr.erase(level_container_Tr.begin() + theLevel);
			}
			return true;
		}
	}

	return false;
}
