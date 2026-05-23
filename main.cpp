#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>

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

vector<int> listaCrescente(int tamanho) {
    vector<int> numeros(tamanho);
    for (int i = 0; i < tamanho; i++) {
        numeros.push_back(i);
    }
    return numeros;
}

vector<int> listaDecrescente(int tamanho) {
    vector<int> numeros(tamanho);
    for (int i = 0; i < tamanho; i++) {
        numeros.push_back(tamanho - i);
    }
    return numeros;
}

vector<int> listaAleatoriaSemRepeticao(int tamanho) {
    vector<int> numeros(tamanho);
    
    return numeros;
}

vector<int> listaAleatoriaComRepeticao(int tamanho) {
    vector<int> numeros(tamanho);

    for (int i = 0; i < tamanho; i++) {
        numeros.push_back(rand());
    }

    return numeros;
}

int main() {

    vector<int> numeros = listaAleatoriaComRepeticao(pow(2, 7));

    auto inicio = chrono::steady_clock::now();

    bubblesort(numeros);

    auto fim = chrono::steady_clock::now();

    auto duracao = fim - inicio;
    auto duracaoNano = chrono::duration_cast<chrono::nanoseconds>(duracao);

    cout << "Tempo gasto para ordenar 128 números: " << duracaoNano.count() << " nanosegundos" << endl;
    
    return 0;
}
