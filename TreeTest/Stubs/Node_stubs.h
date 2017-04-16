#pragma once
#include "../stdafx.h"
#include "CppUnitTest.h"
#include "../../Tree/Node.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//Create section
Node* CREATE_ROOT();
Node* CREATE_CHILDS(unsigned int aNumberOfChalds, Node* aRoot);

//Check section

