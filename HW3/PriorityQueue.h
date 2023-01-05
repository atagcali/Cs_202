/*
* Title: Heaps, Priority Queues
* Author: Alp Tuðrul Aðçalý
* ID: 21801799
* Section: 3
* Assignment: 3
* Description: priority queue header
*/
#pragma once
#include "heap.h"// ADT heap operations
#include "Request.h"
#include "PQException.h"
class PriorityQueue {
public:
	// default constructor, copy constructor, and destructor 
	// are supplied by the compiler

	// priority-queue operations:
	bool pqIsEmpty() const;
	void pqInsert(const Request& newItem) throw (PQException);
	void pqDelete(Request& priorityItem) throw (PQException);

private:
	Heap h;
};