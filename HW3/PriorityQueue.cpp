/*
* Title: Heaps, Priority Queues
* Author: Alp Tuðrul Aðçalý
* ID: 21801799
* Section: 3
* Assignment: 3
* Description: priority queue source
*/
#include "PriorityQueue.h"
#include <iostream>
using namespace std;



bool PriorityQueue::pqIsEmpty() const {
	return h.heapIsEmpty();
}

void PriorityQueue::pqInsert(const Request& newItem) throw (PQException) {
	try {
		h.heapInsert(newItem);
	}
	catch (HeapException e) {
		throw PQException("Priority queue is full");
	}
}

void PriorityQueue::pqDelete(Request& priorityItem) throw (PQException) {
	try {
		h.heapDelete(priorityItem);
	}
	catch (HeapException e) {
		throw PQException("Priority queue is empty");
	}
}