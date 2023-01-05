/*
* Title: Sorting and Algorithm Efficiency
* Author: Alp Tuðrul Aðçalý
* ID: 21801799
* Section: 3
* Assignment: 1
* Description: description of your code
*/


#include <iostream>
#include <cstdlib>
using namespace std;
#include "sorting.h"
void displayArray(const int* arr, const int size);
void createRandomArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size);
void createAlmostSortedArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size);
void createAlmostUnsortedArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size);
void performanceAnalysis(int* arr1, int* arr2, int* arr3, int* arr4);


void displayArray(const int* arr, const int size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        cout << ", ";
    }
    cout << endl;
}

void createRandomArays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size) {
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    arr4 = new int[size];
    for (int i = 0; i < size; i++) {
        arr1[i] = rand() % 10000;
        arr2[i] = rand() % 10000;
        arr3[i] = rand() % 10000;
        arr4[i] = rand() % 10000;
    }
}

void createAlmostSortedArray(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size) {
    int last = size - 1;
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    arr4 = new int[size];
    for (int i = 0; i < size; i++) {
        arr1[i] = i;
        arr2[i] = i;
        arr3[i] = i;
        arr4[i] = i;
    }
    for (int i = 0; i < size; i++) {
        if (i % 20 == 0) {
            swap(arr1[i], arr1[last - i]);
            swap(arr2[i], arr2[last - i]);
            swap(arr3[i], arr3[last - i]);
            swap(arr4[i], arr4[last - i]);
        }
    }
}

void createAlmostUnsortedArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size) {
    int last = size - 1;
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    arr4 = new int[size];
    for (int i = 0; i < size; i++) {
        arr1[i] = last - i;
        arr2[i] = last - i;
        arr3[i] = last - i;
        arr4[i] = last - i;
    }
    for (int i = 0; i < size; i++) {
        if (i % 20 == 0) {
            swap(arr1[i], arr1[last - i]);
            swap(arr2[i], arr2[last - i]);
            swap(arr3[i], arr3[last - i]);
            swap(arr4[i], arr4[last - i]);
        }
    }
}

void performanceAnalysis(int* arr1, int* arr2, int* arr3, int* arr4) {
    sorting sort;
    double duration1 = 0, duration2 = 0, duration3 = 0, duration4 = 0;
    int move1 = 0, move2 = 0, move3 = 0, move4 = 0;
    int comp1 = 0, comp2 = 0, comp3 = 0, comp4 = 0;
    clock_t startTime1, startTime2, startTime3, startTime4;
    int amount = 5000;
    //Analysis of randomly created arrays
    cout << "Analysis of Randomly created arrays" << endl;
    for (int i = 1; i < 9; i++) {
        switch (i) {
        case 1:
            amount = 5000;
            break;
        case 2:
            amount = 10000;
            break;
        case 3:
            amount = 15000;
            break;
        case 4:
            amount = 20000;
            break;
        case 5:
            amount = 25000;
            break;
        case 6:
            amount = 30000;
            break;
        case 7:
            amount = 35000;
            break;
        case 8:
            amount = 40000;
            break;
        }
        duration1 = 0, duration2 = 0, duration3 = 0, duration4 = 0;
        move1 = 0, move2 = 0, move3 = 0, move4 = 0;
        comp1 = 0, comp2 = 0, comp3 = 0, comp4 = 0;

        createRandomArays(arr1, arr2, arr3, arr4, amount);
        startTime1 = clock();
        sort.insertionSort(arr1, amount, comp1, move1);
        duration1 = 1000 * double(clock() - startTime1) / CLOCKS_PER_SEC;

        startTime2 = clock();
        sort.bubbleSort(arr2, amount, comp2, move2);
        duration2 = 1000 * double(clock() - startTime2) / CLOCKS_PER_SEC;

        startTime3 = clock();
        sort.mergeSort(arr3, 0, amount, comp3, move3);
        duration3 = 1000 * double(clock() - startTime3) / CLOCKS_PER_SEC;

        startTime4 = clock();
        sort.quickSort(arr4, 0, amount, comp4, move4);
        duration4 = 1000 * double(clock() - startTime4) / CLOCKS_PER_SEC;

        cout << amount << "-------" << duration1 << "ms-------" << comp1 << "-------" << move1 << endl;
        cout << amount << "-------" << duration2 << "ms-------" << comp2 << "-------" << move2 << endl;
        cout << amount << "-------" << duration3 << "ms-------" << comp3 << "-------" << move3 << endl;
        cout << amount << "-------" << duration4 << "ms-------" << comp4 << "-------" << move4 << endl;
        delete[] arr1, arr2, arr3, arr4;

    }
    //---------------------------------------------------------------------------------------------------------------
    //Analysis of almost sorted arrays
    cout << "Analysis of Almost sorted arrays" << endl;
    for (int i = 1; i < 9; i++) {
        switch (i) {
        case 1:
            amount = 5000;
            break;
        case 2:
            amount = 10000;
            break;
        case 3:
            amount = 15000;
            break;
        case 4:
            amount = 20000;
            break;
        case 5:
            amount = 25000;
            break;
        case 6:
            amount = 30000;
            break;
        case 7:
            amount = 35000;
            break;
        case 8:
            amount = 40000;
            break;
        }
        duration1 = 0, duration2 = 0, duration3 = 0, duration4 = 0;
        move1 = 0, move2 = 0, move3 = 0, move4 = 0;
        comp1 = 0, comp2 = 0, comp3 = 0, comp4 = 0;

        createAlmostSortedArray(arr1, arr2, arr3, arr4, amount);
        startTime1 = clock();
        sort.insertionSort(arr1, amount, comp1, move1);
        duration1 = 1000 * double(clock() - startTime1) / CLOCKS_PER_SEC;

        startTime2 = clock();
        sort.bubbleSort(arr2, amount, comp2, move2);
        duration2 = 1000 * double(clock() - startTime2) / CLOCKS_PER_SEC;

        startTime3 = clock();
        sort.mergeSort(arr3, 0, amount, comp3, move3);
        duration3 = 1000 * double(clock() - startTime3) / CLOCKS_PER_SEC;

        startTime4 = clock();
       // sort.quickSort(arr4, 0, amount, comp4, move4);
        duration4 = 1000 * double(clock() - startTime4) / CLOCKS_PER_SEC;

        cout << amount << "-------" << duration1 << "ms-------" << comp1 << "-------" << move1 << endl;
        cout << amount << "-------" << duration2 << "ms-------" << comp2 << "-------" << move2 << endl;
        cout << amount << "-------" << duration3 << "ms-------" << comp3 << "-------" << move3 << endl;
        cout << amount << "-------" << duration4 << "ms-------" << comp4 << "-------" << move4 << endl;
        delete[] arr1, arr2, arr3, arr4;

    }    cout << "Analysis of Almost unsorted arrays" << endl;
    for (int i = 1; i < 9; i++) {
        switch (i) {
        case 1:
            amount = 5000;
            break;
        case 2:
            amount = 10000;
            break;
        case 3:
            amount = 15000;
            break;
        case 4:
            amount = 20000;
            break;
        case 5:
            amount = 25000;
            break;
        case 6:
            amount = 30000;
            break;
        case 7:
            amount = 35000;
            break;
        case 8:
            amount = 40000;
            break;
        }
        duration1 = 0, duration2 = 0, duration3 = 0, duration4 = 0;
        move1 = 0, move2 = 0, move3 = 0, move4 = 0;
        comp1 = 0, comp2 = 0, comp3 = 0, comp4 = 0;

        createAlmostUnsortedArrays(arr1, arr2, arr3, arr4, amount);
        startTime1 = clock();
        sort.insertionSort(arr1, amount, comp1, move1);
        duration1 = 1000 * double(clock() - startTime1) / CLOCKS_PER_SEC;

        startTime2 = clock();
        sort.bubbleSort(arr2, amount, comp2, move2);
        duration2 = 1000 * double(clock() - startTime2) / CLOCKS_PER_SEC;

        startTime3 = clock();
        sort.mergeSort(arr3, 0, amount, comp3, move3);
        duration3 = 1000 * double(clock() - startTime3) / CLOCKS_PER_SEC;

        startTime4 = clock();
        //sort.quickSort(arr4, 0, amount, comp4, move4);
        duration4 = 1000 * double(clock() - startTime4) / CLOCKS_PER_SEC;

        cout << amount << "-------" << duration1 << "ms-------" << comp1 << "-------" << move1 << endl;
        cout << amount << "-------" << duration2 << "ms-------" << comp2 << "-------" << move2 << endl;
        cout << amount << "-------" << duration3 << "ms-------" << comp3 << "-------" << move3 << endl;
        cout << amount << "-------" << duration4 << "ms-------" << comp4 << "-------" << move4 << endl;
        delete[] arr1, arr2, arr3, arr4;

    }
}



int main()
{
    sorting s1;
    int* arr1 = new int[0];
    int* arr2 = new int[0];
    int* arr3 = new int[0];
    int* arr4 = new int[0];
    int comp = 0;
    int move = 0;
 
    int* theArray = new int[16];
    theArray[0] = 9;
    theArray[1] = 6;
    theArray[2] = 7;
    theArray[3] = 16;
    theArray[4] = 18;
    theArray[5] = 5;
    theArray[6] = 2;
    theArray[7] = 12;
    theArray[8] = 20;
    theArray[9] = 1;
    theArray[10] = 16;
    theArray[11] = 17;
    theArray[12] = 4;
    theArray[13] = 11;
    theArray[14] = 13;
    theArray[15] = 8;


    s1.insertionSort(theArray, 16, comp, move);
    displayArray(theArray, 16);
    s1.bubbleSort(theArray, 16, comp, move);
    displayArray(theArray, 16);
    s1.mergeSort(theArray, 0, 16, comp, move);
    displayArray(theArray, 16);
    s1.quickSort(theArray, 0, 16, comp, move);
    displayArray(theArray, 16);
    delete[] theArray;
    delete[] arr1, arr2, arr3, arr4;
    performanceAnalysis(arr1,arr2,arr3,arr4);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
