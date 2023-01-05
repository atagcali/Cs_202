#include <string>
#include <iostream>
using namespace std;
#include "BinaryNode.h"

/*
* Title: Trees
* Author: Alp Tuðrul Aðçalý
* ID: 21801799
* Section: 3
* Assignment: 2
*/
class BinarySearchTree {
public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree& tree);
	/*~BinarySearchTree();*/

	bool isEmpty() const;
	int getHeight();
	int getNumberOfNodes();
	bool add(int newEntry);
	bool remove(int anEntry);
	bool contains(int anEntry);
	void inorderTraverse();
	void showRoot();
	int getWidth();
	int count(int a, int b);
	int select(int anEntry);
	int successor(int anEntry);
private:
	void next(int anEntry, int& result, BinaryNode* node, bool& set);
	void order(int anEntry, int& order1, int& ordercounter, BinaryNode* node);
	void searchForcount(int a, int b, BinaryNode* root, int& amount);
	void searchwidth(BinaryNode* root, int height, int*& arr);
	void traverse(BinaryNode* root);



	BinaryNode* root;
	int height;
};
