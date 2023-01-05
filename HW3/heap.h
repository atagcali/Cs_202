/*
* Title: Heaps, Priority Queues
* Author: Alp Tuðrul Aðçalý
* ID: 21801799
* Section: 3
* Assignment: 3
* Description: heap header
*/
#pragma once
const int MAX_HEAP = 100;
#include "Request.h"// definition of KeyedItem
#include "HeapException.h"
class Heap {
public:
	Heap();				// default constructor
	// copy constructor and destructor are supplied by the compiler

	bool heapIsEmpty() const;
	void heapInsert(const Request& newItem) throw(HeapException);
	void heapDelete(Request& rootItem) throw(HeapException);
protected:
	void heapRebuild(int root);		// Converts the semiheap rooted at 
							// index root into a heap
private:
	Request items[MAX_HEAP];	// array of heap items
	int          size;            	// number of heap items
};
