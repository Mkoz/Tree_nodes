// Tree.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Node.h"

int main()
{
    //1
	PRINT << endl;


	string tmpTag = "<root>";
	string tmpTagC = "aaaaaaaa";
	string tmpId = "root";
	Node* tmpNode = new Node(NULL, &tmpTag, &tmpTagC, &tmpId);
	system("pause");
	return 0;
}

