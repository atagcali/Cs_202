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

int main () {
	BinarySearchTree a;
	a.isEmpty();
	a.add(10);
	a.add(15);
	a.add(8);
	a.add(5);
	a.add(9);
	a.add(13);
	a.add(18);
	a.add(16);
	a.add(20);
	a.add(1);
	a.add(7);
	a.add(6);
	a.add(21);

	a.inorderTraverse();

	cout <<"height is " << a.getHeight() << endl;
	cout <<"width is " << a.getWidth() << endl;

	cout << "count is " << a.count(4, 19) << endl;
	cout << "select " << a.select(7) << endl;
	cout << "sucessor " << a.successor(15) << endl;

	a.remove(16);
	a.remove(20);

	cout << "count is " << a.count(4, 19) << endl;
	cout << "select " << a.select(7) << endl;
	cout << "sucessor " << a.successor(15) << endl;

	a.inorderTraverse();
	return 0;
}