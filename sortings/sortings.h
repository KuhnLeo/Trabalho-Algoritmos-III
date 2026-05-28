#ifndef SORTINGS_H
#define SORTINGS_H

#include <vector>

using namespace std;

void bubbleSort(vector<int>& array);

void insertionSort(vector<int>& array);

void selectionSort(vector<int>& array);

void heapSort(vector<int>& array);

void shellSort(vector<int>& arr);
 
void mergeSort(vector<int>& arr, int esq, int dir);

#endif
