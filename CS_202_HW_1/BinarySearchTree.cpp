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
#include "BinarySearchTree.h"


BinarySearchTree::BinarySearchTree() : root(NULL), height(0){

}

bool BinarySearchTree::isEmpty() const {
	if (root == NULL)
		return true;

	return false;
}

int BinarySearchTree::getNumberOfNodes() {
	return root->size;
}

int BinarySearchTree::getHeight() {
	if (root == NULL) {
		return 0;
	}
	else {
		BinaryNode* temp = root;
		root = root->leftChild;
		int leftHeight = getHeight();
		root = temp;
		root = root->rightChild;
		int rightHeight = getHeight();
		root = temp;

		if (leftHeight > rightHeight)
			return leftHeight + 1;
		else
			return rightHeight + 1;
		delete temp;
		temp = NULL;

	}
}

bool BinarySearchTree::add(int newEntry) {
	if (newEntry <= 0 || contains(newEntry)) {
		return 0;
	}

	else if (isEmpty()) {
		root = new BinaryNode(newEntry);
		root->size++;
		return true;			
	}
	else {
		BinaryNode* node = root;

		if (newEntry < root->data) {
			root = root->leftChild;
			add(newEntry);
			node->leftChild = root;
			root->parent = node;
		}
		else  {
			root = root->rightChild;
			add(newEntry);
			node->rightChild = root;
			root->parent = node;
		}

		root->size++;
		root = node;	
		node = NULL;
		
		return true;
	}
}

bool BinarySearchTree::remove(int anEntry) {
	if (!contains(anEntry))
		return 0;
	else {
		BinaryNode* deleteNode = root;
		while (deleteNode->data != anEntry) {
			if (anEntry < deleteNode->data) {
				deleteNode = deleteNode->leftChild;
			}
			else {
				deleteNode = deleteNode->rightChild;
			}
		}

		// Test for Leaf
		if ((deleteNode->rightChild == NULL) && (deleteNode->leftChild == NULL)) {			
			if (deleteNode->parent->rightChild != NULL && deleteNode->parent->rightChild->data == deleteNode->data)
				deleteNode->parent->rightChild = NULL;
			else if(deleteNode->parent->leftChild != NULL && deleteNode->parent->leftChild->data == deleteNode->data)
				deleteNode->parent->leftChild = NULL;

			delete deleteNode;
			deleteNode = NULL;
			return 1;
		}

		// Test for have right child

		else if ((deleteNode->rightChild != NULL) && (deleteNode->leftChild == NULL)) {
			BinaryNode* tempNode;
			tempNode = deleteNode->rightChild;
			tempNode->parent = deleteNode->parent;
			if (deleteNode->parent->rightChild != NULL && deleteNode->parent->rightChild->data == deleteNode->data)
				deleteNode->parent->rightChild = tempNode;
			else if (deleteNode->parent->leftChild != NULL && deleteNode->parent->leftChild->data == deleteNode->data)
				deleteNode->parent->leftChild = tempNode;
			delete deleteNode;
			deleteNode = NULL;
			return 1;
		}

		//for left child

		else if ((deleteNode->rightChild == NULL) && (deleteNode->leftChild != NULL)) {
			BinaryNode* tempNode;
			tempNode = deleteNode->leftChild;
			//connect with parent
			tempNode->parent = deleteNode->parent;
			if (deleteNode->parent->rightChild != NULL && deleteNode->parent->rightChild->data == deleteNode->data)
				deleteNode->parent->rightChild = tempNode;
			else if (deleteNode->parent->leftChild != NULL && deleteNode->parent->leftChild->data == deleteNode->data)
				deleteNode->parent->leftChild = tempNode;

			delete deleteNode;
			deleteNode = NULL;
			return 1;
		}
		//for 2 children
		else {
			bool leftChildExists = false;
			BinaryNode* tempNode;
			tempNode = deleteNode->rightChild;
			while(tempNode->leftChild != NULL) {
				tempNode = tempNode->leftChild;
				leftChildExists = true;
			} 
			if (leftChildExists) {
				tempNode->parent->leftChild = NULL;
				//connect with parent
				if (deleteNode->parent->rightChild != NULL && deleteNode->parent->rightChild->data == deleteNode->data)
					deleteNode->parent->rightChild = tempNode;
				else if (deleteNode->parent->leftChild != NULL && deleteNode->parent->leftChild->data == deleteNode->data)
					deleteNode->parent->leftChild = tempNode;
				tempNode->parent = deleteNode->parent;
				//connect with right child
				if (deleteNode->rightChild != NULL)
					tempNode->rightChild = deleteNode->rightChild;
				deleteNode->rightChild->parent = tempNode;
				//connect with left child
				if (deleteNode->leftChild != NULL)
					tempNode->leftChild = deleteNode->leftChild;
				deleteNode->leftChild->parent = tempNode;

				delete deleteNode;
				deleteNode = NULL;
				return 1;
			}
			else {
				tempNode->parent->rightChild = NULL;
				//connect with parent
				if (deleteNode->parent->rightChild != NULL && deleteNode->parent->rightChild->data == deleteNode->data)
					deleteNode->parent->rightChild = tempNode;
				else if (deleteNode->parent->leftChild != NULL && deleteNode->parent->leftChild->data == deleteNode->data)
					deleteNode->parent->leftChild = tempNode;
				tempNode->parent = deleteNode->parent;
				//connect with right child
				tempNode->rightChild = deleteNode->rightChild;
				if(deleteNode->rightChild != NULL)
					deleteNode->rightChild->parent = tempNode;
				//connect with left child
				if (deleteNode->leftChild != NULL)
					tempNode->leftChild = deleteNode->leftChild;
				deleteNode->leftChild->parent = tempNode;

				delete deleteNode;
				deleteNode = NULL;
				return 1;
			}

		}

	}
}

bool BinarySearchTree::contains(int anEntry) {
	bool finded;
	if (root == NULL)
		return 0;
	else {
		if (anEntry == (root->data) ) {
			return 1;
		}
		else {
			BinaryNode* node = root;
			if (anEntry < root->data) {
				root = root->leftChild;
				finded = contains(anEntry);
			}
			else {
				root = root->rightChild;
				finded = contains(anEntry);
			}
			root = node;
			node = NULL;	
			return finded;
		}
	}
}

void BinarySearchTree::inorderTraverse() {
	
	traverse(root);
	cout << endl;
	/*if (root != NULL) {
		BinaryNode* temp;
		//cout << root->data << endl;
		temp = root;
		root = root->leftChild;
		inorderTraverse();
		root = temp;
		cout << root->data << "  ";
		temp = root;
		root = root->rightChild;
		inorderTraverse();
		root = temp;
		delete temp;
		temp = NULL;
	}*/
}
void BinarySearchTree::traverse(BinaryNode* root) {
	if (root != NULL) {
		traverse(root->leftChild);
		cout << root->data << "  ";
		traverse(root->rightChild);
	}
}


int BinarySearchTree::getWidth() {
	int a = getHeight();
	int* array = new int[a];
	for (int i = 0; i < a; i++) {
		array[i] = 0;
	}
	searchwidth(root,a,array);
	int max = 0;
	for (int i = 0; i < a; i++) {
		if (array[i] > max)
			max = array[i];
	}
	return max;
}
void BinarySearchTree::searchwidth(BinaryNode* root,int height, int*& arr) {
	if (root != NULL){	
		searchwidth(root->leftChild, height, arr);
		searchwidth(root->rightChild, height, arr);

		BinaryNode* temp;
		temp = root;
		int parentAmount = 0;
		while (temp->parent != NULL) {
			parentAmount++;
			temp = temp->parent;
		}

		arr[height - (parentAmount+1)]++;
	}
}

int BinarySearchTree::count(int a, int b) {
	BinaryNode* temp = root;
	int amount = 0;
	searchForcount(a, b, temp, amount);
	return amount;
}
void BinarySearchTree::searchForcount(int a, int b,BinaryNode* root,int& amount) {
	if (root != NULL) {
		if (root->data < a && root->data < b) {
			searchForcount(a, b, root->rightChild, amount);
		}
		else if (root->data > a && root->data > b) {
			searchForcount(a, b, root->leftChild, amount);
		}
		else if (root->data > a && root->data < b) {
			searchForcount(a, b, root->rightChild, amount);
			searchForcount(a, b, root->leftChild, amount);
			amount++;
		}
	}
}

int BinarySearchTree::select(int anEntry) {
	int orders = 0;
	int ordercounter = 0;
	BinaryNode* node = root;
	order(anEntry, orders, ordercounter, root);
	
	return orders-1;
}
void BinarySearchTree::order(int anEntry, int& orders, int& ordercounter, BinaryNode* node) {
	if (node != NULL) {
		order(anEntry, orders, ordercounter, node->leftChild);
		ordercounter++;
		if (anEntry == node->data) {
			orders = ordercounter;
		}
		order(anEntry, orders, ordercounter, node->rightChild);
	}
}

int BinarySearchTree::successor(int anEntry) {
	int sucessor = -1;
	bool set = 0;
	BinaryNode* node = root;
	next(anEntry, sucessor, node,set);
	return sucessor;
}
void BinarySearchTree::next(int anEntry, int& result, BinaryNode* node, bool& set) {
	if (node != NULL) {
		next(anEntry, result, node->leftChild, set);
		if (set) {
			result = node->data;
			set = 0;
		}
		if (anEntry == node->data) {
			set = 1;
		}
		next(anEntry, result, node->rightChild, set);
	}
}


