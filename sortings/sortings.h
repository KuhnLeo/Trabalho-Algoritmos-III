#ifndef SORTINGS_H
#define SORTINGS_H

#include <vector>

using namespace std;

void bubbleSort(vector<int>& array);

void insertionSort(vector<int>& array);

void selectionSort(vector<int>& array);

void heapSort(vector<int>& array);

void shellSort(vector<int>& array);
 
void mergeSort(vector<int>& array, int esq, int dir);

void quickSort(vector<int>& array, int esq, int dir);

#endif
