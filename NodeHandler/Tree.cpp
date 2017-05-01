// NodeHandler.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Tree.h"

using namespace std;
Tree::Tree():level_container_Tr(NULL)
{
	PRINT << "size: " << level_container_Tr.size() << endl;
}

bool Tree::add_node_Tr(Node* aRoot,string *aTag, string *aTagC, string *anId)
{
	auto levelSize = level_container_Tr.size();
	if ( levelSize == 0 )
	{
		PRINT << "Root case" << endl;
		//vector<Node> tmpNode(nullptr, aTag, aTagC, anId);
		level_container_Tr.push_back(vector<Node>());
		PRINT << "Root case size: " << level_container_Tr[0].size() << endl;
		level_container_Tr[0].push_back(Node(nullptr, aTag, aTagC, anId, 0));
		//.push_back((nullptr, aTag, aTagC, anId)))
	} else {
		PRINT << "Not root case" << endl;
		PRINT << "Not root case size: " << level_container_Tr.size() << endl;
		auto rootLevel = aRoot->get_level();
		PRINT << "Not root case. Size: " << levelSize << " level: " << rootLevel << endl;
		auto delta = levelSize - rootLevel;
		if ( delta >= 2)
		{
			PRINT_ERROR << "Previous level has been missed. Level: " << rootLevel << " Size: " << levelSize << endl;
			return false;
		}
		if (delta == 1)
		{
			//level_container_Tr does not contain current level yet.
			level_container_Tr.push_back(vector<Node>());
		}
		auto id = create_id_Tr(aRoot, *aTag);
		level_container_Tr[rootLevel + 1].push_back(Node(aRoot, aTag, aTagC, &id, rootLevel+1 ));
	}

	return true;
}

Node * Tree::get_node_by_id_Tr(string* anId)
{
	unsigned int counter = 0;
	for (vector<vector<Node>>::iterator it = level_container_Tr.begin(); it != level_container_Tr.end(); it++, counter++)
	{
		for (auto iter = level_container_Tr[counter].begin(); iter != level_container_Tr[counter].end(); iter++)
		{
			if (iter->get_id() == *anId)
			{
				return &*iter;
			}
		}
	}
	return nullptr;
}

void Tree::print_tree_Tr()
{
	unsigned int counter = 0;
	for (vector<vector<Node>>::iterator it = level_container_Tr.begin(); it != level_container_Tr.end(); it++, counter++ )
	{
		PRINT << "================ LEVEL " << counter << "=====================" << endl;
		for (auto iter = level_container_Tr[counter].begin(); iter != level_container_Tr[counter].end(); iter++)
		{
			iter->print_node();
		}
	}
}

string Tree::create_id_Tr(Node* aRoot, string aTag)
{
	// Id looks like root.tag<number of repeats on level>.tag<number of repeats on level>
	aTag.erase(aTag.find('<'), 1);
	aTag.erase(aTag.find('>'), 1);
	string theId = aRoot->get_id() + "." + aTag;
	unsigned int numberOfRepeats = 0;
	for (auto iter = level_container_Tr[aRoot->get_level() + 1].begin(); iter != level_container_Tr[aRoot->get_level() + 1].end(); iter++)
	{
		if ( aTag == iter->get_tag())
		{
			numberOfRepeats++ ;
		}
	}

	theId = theId + to_string(numberOfRepeats);
	PRINT << theId << endl;
	return theId;
}
