/*
* Title: Trees
* Author: Alp Tuðrul Aðçalý
* ID: 21801799
* Section: 3
* Assignment: 2
*/
#include <string>
#include <iostream>
using namespace std;
#include "BinaryNode.h"

BinaryNode::BinaryNode() {

}

BinaryNode::BinaryNode(const int& nodeItem, BinaryNode* Left, BinaryNode* Right, BinaryNode* Parent) :
												data(nodeItem), size(0), leftChild(Left), rightChild(Right), parent(Parent) 
{

}