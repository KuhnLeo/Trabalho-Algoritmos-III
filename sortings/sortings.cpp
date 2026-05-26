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




