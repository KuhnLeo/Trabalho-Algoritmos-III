#include <iostream>
#include <vector>
#include <chrono>

#include "listCreator.h"

using namespace std;

void bubblesort(vector<int>& array) {
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

int main() {
    int var;
    
    vector<int> numeros = listaAleatoriaComRepeticao(var));

    auto inicio = chrono::steady_clock::now();

    bubblesort(numeros);

    auto fim = chrono::steady_clock::now();

    auto duracao = fim - inicio;
    auto duracaoNano = chrono::duration_cast<chrono::nanoseconds>(duracao);

    cout << "Tempo gasto para ordenar " << var << " números: " << duracaoNano.count() << " nanosegundos" << endl;
    
    return 0;
}
