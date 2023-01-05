/*
* Title: Heaps, Priority Queues
* Author: Alp Tuðrul Aðçalý
* ID: 21801799
* Section: 3
* Assignment: 3
* Description: heap source
*/
#include "heap.h"
#include <iostream>
using namespace std;

// Default constructor 
Heap::Heap() : size(0) {

}

bool Heap::heapIsEmpty() const {
	return (size == 0);
}

void Heap::heapInsert(const Request& newItem) throw(HeapException) {

	if (size >= MAX_HEAP)
		throw HeapException("HeapException: Heap full");

	// Place the new item at the end of the heap
	items[size] = newItem;

	// Trickle new item up to its proper position
	int place = size;
	int parent = (place - 1) / 2;
	while ((place > 0) && (items[place].getPriority() > items[parent].getPriority())) {
		Request temp = items[parent];
		items[parent] = items[place];
		items[place] = temp;

		place = parent;
		parent = (place - 1) / 2;
	}
	++size;
}

void Heap::heapDelete(Request& rootItem) throw(HeapException) {
	if (heapIsEmpty())
		throw HeapException("HeapException: Heap empty");
	else {
		rootItem = items[0];
		items[0] = items[--size];
		heapRebuild(0);
	}
}

void Heap::heapRebuild(int root) {
	int child = 2 * root + 1; 	// index of root's left child, if any
	if (child < size) {
		// root is not a leaf so that it has a left child
		int rightChild = child + 1; 	// index of a right child, if any
		// If root has right child, find larger child
		if ((rightChild < size) &&
			(items[rightChild].getPriority() > items[child].getPriority()))
			child = rightChild; 	// index of larger child

		// If root’s item is smaller than larger child, swap values
		if (items[root].getPriority() < items[child].getPriority()) {
			Request temp = items[root];
			items[root] = items[child];
			items[child] = temp;

			// transform the new subtree into a heap
			heapRebuild(child);
		}
	}
}
