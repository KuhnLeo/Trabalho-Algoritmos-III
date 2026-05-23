#include <iostream>
#include <vector>
#include <cmath>

#include "listCreator.h"
using namespace std;

vector<int> listaCrescente(int tamanho) {
    vector<int> numeros(tamanho);
    for (int i = 0; i < tamanho; i++) {
        numeros[i] = i;
    }
    return numeros;
}

vector<int> listaDecrescente(int tamanho) {
    vector<int> numeros(tamanho);
    for (int i = 0; i < tamanho; i++) {
        numeros[i] = tamanho - i;
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
        numeros[i] = rand();
    }

    return numeros;
}
