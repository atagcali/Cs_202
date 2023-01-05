/*
* Title: Sorting and Algorithm Efficiency
* Author: Alp Tuðrul Aðçalý
* ID: 21801799
* Section: 3
* Assignment: 1
* Description: description of your code
*/
#pragma once
#ifndef __SORTING_H
#define __SORTING_H
#include <iostream>
using namespace std;

class sorting {

public:
	void insertionSort(int* arr, const int size, int& compCount, int& moveCount);
	void bubbleSort(int* arr, const int size, int& compCount, int& moveCount);
	void mergeSort(int* arr, int first,  int size, int& compCount, int& moveCount);
	void quickSort(int* arr, int first, int size, int& compCount, int& moveCount);
	void merge(int* theArray, int first, int mid, int last , int& compCount, int& moveCount);
	void partition(int* theArray, int first, int last, int& pivotIndex, int& compCount, int& moveCount);
	//void swap(int& x, int& y);
};
#endif