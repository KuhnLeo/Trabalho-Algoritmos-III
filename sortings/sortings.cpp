#include <iostream>
#include <vector>
#include <algorithm>

#include "sortings.h"

using namespace std;

void bubbleSort(vector<int>& array) {
    int n = array.size();
    bool swapped;

    for (int i = 0; i<n-1; i++) {
        swapped = false;
        for (int j = 0; j < n-i-1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j+1]);
                swapped = true;
            }
        }

        if(!swapped) {
            break;
        }
    }
}

void insertionSort(vector<int>& array){
    int n = array.size();
      for (int i = 1; i < n; ++i) {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

void selectionSort(vector<int>& array){
    int n = array.size();

    for(int i = 0; i < n - 1; i++){
        int menor = array[i];
        int posicao = i;
        bool troca = false;
        for(int j = i + 1; j < n; j ++){
            if(menor > array[j]){
                menor = array[j];
                posicao = j;
                troca = true;
            }
        }
        if(troca){
            swap(array[i], array[posicao]);
        }
    }
}

static void heapify(vector<int>& array, int n, int i) {
    int maior = i;
    int esq   = 2 * i + 1;
    int dir   = 2 * i + 2;
 
    if (esq < n && array[esq] > array[maior]) maior = esq;
    if (dir < n && array[dir] > array[maior]) maior = dir;
 
    if (maior != i) {
        swap(array[i], array[maior]);
        heapify(array, n, maior);
    }
}

void heapSort(vector<int>& array) {
    int n = array.size();
 
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(array, n, i);
    }
 
    for (int i = n - 1; i > 0; i--) {
        swap(array[0], array[i]);   
        heapify(array, i, 0);     
    }
}

void shellSort(vector<int>& array) {
    int n = array.size();
 
    int gap = 1;
    while (gap < n / 3) gap = gap * 3 + 1;
 
    while (gap >= 1) {
        for (int i = gap; i < n; i++) {
            int chave = array[i];
            int j = i;
            while (j >= gap && array[j - gap] > chave) {
                array[j] = array[j - gap];
                j -= gap;
            }
            array[j] = chave;
        }
        gap /= 3;
    }
}

static void merge(vector<int>& array, int esq, int meio, int dir) {
    vector<int> L(array.begin() + esq,    array.begin() + meio + 1);
    vector<int> R(array.begin() + meio + 1, array.begin() + dir  + 1);
 
    int i = 0, j = 0, k = esq;
    while (i < (int)L.size() && j < (int)R.size()) {
        if (L[i] <= R[j]) array[k++] = L[i++];
        else               array[k++] = R[j++];
    }
    while (i < (int)L.size()) array[k++] = L[i++];
    while (j < (int)R.size()) array[k++] = R[j++];
}
 
void mergeSort(vector<int>& array, int esq, int dir) {
    if (esq >= dir) return;
    int meio = esq + (dir - esq) / 2;
    mergeSort(array, esq, meio);
    mergeSort(array, meio + 1, dir);
    merge(array, esq, meio, dir);
}

void quickSort(vector<int>& array, int esq, int dir) {
    if (esq >= dir) return;

    
    int meio = esq + (dir - esq) / 2;

    if (array[esq] > array[meio])  swap(array[esq], array[meio]);
    if (array[esq] > array[dir])   swap(array[esq], array[dir]);
    if (array[meio] > array[dir])  swap(array[meio], array[dir]);
    
    swap(array[meio], array[dir]);

   
    int pivo = array[dir];
    int i = esq - 1;

    for (int j = esq; j < dir; j++) {
        if (array[j] <= pivo) {
            i++;
            swap(array[i], array[j]);
        }
    }

    swap(array[i + 1], array[dir]);
    int p = i + 1;

    quickSort(array, esq, p - 1);
    quickSort(array, p + 1, dir);
}
