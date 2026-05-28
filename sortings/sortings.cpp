#include <iostream>
#include <vector>
#include <algorithm>

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

static void heapify(vector<int>& arr, int n, int i) {
    int maior = i;
    int esq   = 2 * i + 1;
    int dir   = 2 * i + 2;
 
    if (esq < n && arr[esq] > arr[maior]) maior = esq;
    if (dir < n && arr[dir] > arr[maior]) maior = dir;
 
    if (maior != i) {
        swap(arr[i], arr[maior]);
        heapify(arr, n, maior);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
 
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
 
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);   
        heapify(arr, i, 0);     
    }
}

void shellSort(vector<int>& arr) {
    int n = arr.size();
 
    int gap = 1;
    while (gap < n / 3) gap = gap * 3 + 1;
 
    while (gap >= 1) {
        for (int i = gap; i < n; i++) {
            int chave = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > chave) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = chave;
        }
        gap /= 3;
    }
}

static void merge(vector<int>& arr, int esq, int meio, int dir) {
    vector<int> L(arr.begin() + esq,    arr.begin() + meio + 1);
    vector<int> R(arr.begin() + meio + 1, arr.begin() + dir  + 1);
 
    int i = 0, j = 0, k = esq;
    while (i < (int)L.size() && j < (int)R.size()) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else               arr[k++] = R[j++];
    }
    while (i < (int)L.size()) arr[k++] = L[i++];
    while (j < (int)R.size()) arr[k++] = R[j++];
}
 
void mergeSort(vector<int>& arr, int esq, int dir) {
    if (esq >= dir) return;
    int meio = esq + (dir - esq) / 2;
    mergeSort(arr, esq, meio);
    mergeSort(arr, meio + 1, dir);
    merge(arr, esq, meio, dir);
}
