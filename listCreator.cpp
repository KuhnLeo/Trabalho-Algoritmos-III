#include <iostream>
#include <vector>
#include <cmath>

#include "listCreator.h"
using namespace std;

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
