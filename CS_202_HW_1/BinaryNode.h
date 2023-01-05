/*
* Title: Trees
* Author: Alp Tuðrul Aðçalý
* ID: 21801799
* Section: 3
* Assignment: 2
*/
#pragma once
#include <string>
#include <iostream>
using namespace std;

class BinaryNode {
private:
	BinaryNode();
	BinaryNode(const int& nodeItem, BinaryNode* Left = NULL, BinaryNode* Right = NULL, BinaryNode* Parent = NULL);

	int data;
	int size;
	BinaryNode* leftChild;
	BinaryNode* rightChild;
	BinaryNode* parent;

	friend class BinarySearchTree;
};