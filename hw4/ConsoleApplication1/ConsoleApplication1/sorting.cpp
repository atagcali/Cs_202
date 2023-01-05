/*
* Title: Sorting and Algorithm Efficiency
* Author: Alp Tuðrul Aðçalý
* ID: 21801799
* Section: 3
* Assignment: 1
* Description: description of your code
*/
#include <iostream>
#include "sorting.h"

using namespace std;


void sorting::insertionSort(int* arr, const int size, int& compCount, int& moveCount) {
    for (int unsorted = 1; unsorted < size; ++unsorted) {
        moveCount++;
        compCount++;

        int nextItem = arr[unsorted];
        moveCount++;
        int loc = unsorted;
        moveCount++;

        for (; (loc > 0) && (arr[loc - 1] > nextItem); --loc) {
            moveCount++;
            compCount++;

            arr[loc] = arr[loc - 1];
            moveCount++;
        }
        arr[loc] = nextItem;
        moveCount++;

    }
}


void sorting::bubbleSort(int* arr, const int size, int& compCount, int& moveCount) {
    bool sorted = false;
    moveCount++;

    for (int pass = 1; (pass < size) && !sorted; ++pass) {
        moveCount++;
        compCount++;

        sorted = true;
        moveCount++;

        for (int index = 0; index < size - pass; ++index) {
            moveCount++;
            compCount++;

            int nextIndex = index + 1;
            moveCount++;

            if (arr[index] > arr[nextIndex]) {
                compCount++;

                swap(arr[index], arr[nextIndex]);
                sorted = false; // signal exchang
                moveCount = moveCount + 5;
            }
        }
    }

}


void sorting::mergeSort(int* arr, const int first, const int size, int& compCount, int& moveCount) {
    if (first < size -1 ) {
        moveCount++;
        compCount++;

        int mid = (first + size -1 ) / 2; 	// index of midpoint
        moveCount++;

        mergeSort(arr, first, mid +1, compCount, moveCount);

        mergeSort(arr, mid + 1, size, compCount, moveCount);

        // merge the two halves
        merge(arr, first, mid, size-1, compCount, moveCount);
    }
}  // end mergesort

void sorting::merge(int* theArray, int first, int mid, int last, int& compCount, int& moveCount) {
    int* tempArray = new int[last+1];	// temporary array
    moveCount++;

    int first1 = first; 	// beginning of first subarray
    moveCount++;

    int last1 = mid; 		// end of first subarray
    moveCount++;

    int first2 = mid + 1;	// beginning of second subarray
    moveCount++;

    int last2 = last;		// end of second subarray
    moveCount++;

    int index = first1; // next available location in tempArray
    moveCount++;


    for (; (first1 <= last1) && (first2 <= last2); ++index) {
        moveCount++;
        compCount++;

        if (theArray[first1] < theArray[first2]) {
            moveCount++;
            compCount++;

            tempArray[index] = theArray[first1];
            moveCount++;

            ++first1;
            moveCount++;

        }
        else {
            tempArray[index] = theArray[first2];
            moveCount++;

            ++first2;
            moveCount++;

        }
    }

    // finish off the first subarray, if necessary
    for (; first1 <= last1; ++first1, ++index) {
        moveCount++;
        compCount++;

        tempArray[index] = theArray[first1];
        moveCount++;
    }

    // finish off the second subarray, if necessary
    for (; first2 <= last2; ++first2, ++index) {
        moveCount++;
        compCount++;

        tempArray[index] = theArray[first2];
        moveCount++;
    }

    // copy the result back into the original array
    for (index = first; index <= last; ++index) {
        moveCount++;
        compCount++;

        theArray[index] = tempArray[index];
        moveCount++;
    }
    delete[] tempArray;
}  // end merge

void sorting::quickSort(int* arr, const int first, int size, int& compCount, int& moveCount) {
    
    int pivotIndex;


    if (first < size -1) {
        moveCount++;

        // create the partition: S1, pivot, S2
        partition(arr, first, size - 1, pivotIndex, compCount, moveCount);

        // sort regions S1 and S2
        quickSort(arr, first, pivotIndex, compCount, moveCount);
        quickSort(arr, pivotIndex + 1, size, compCount, moveCount);
    }

}

void sorting::partition(int* theArray, int first, int last, int& pivotIndex, int& compCount, int& moveCount) {
    
    int pivot = theArray[first];
    moveCount++;

    // initially, everything but pivot is in unknown
    int lastS1 = first;           // index of last item in S1
    moveCount++;

    int firstUnknown = first + 1; // index of first item in unknown
    moveCount++;


     // move one item at a time until unknown region is empty
    for (; firstUnknown <= last; ++firstUnknown) {
        moveCount++;
        compCount++;
        // Invariant: theArray[first+1..lastS1] < pivot
        //            theArray[lastS1+1..firstUnknown-1] >= pivot

        // move item from unknown to proper region
        if (theArray[firstUnknown] < pivot) {  	// belongs to S1
            moveCount++;
            compCount++;

            ++lastS1;
            moveCount++;

            swap(theArray[firstUnknown], theArray[lastS1]);
            moveCount = moveCount + 3;
        }	// else belongs to S2
    }
    // place pivot in proper position and mark its location
    swap(theArray[first], theArray[lastS1]);
    moveCount = moveCount + 3;

    pivotIndex = lastS1;
    moveCount++;

}


