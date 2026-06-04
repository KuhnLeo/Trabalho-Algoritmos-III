#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <algorithm>

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
    vector<int> numeros;
    for (int i = 0; i < tamanho; i++) {
        numeros.push_back(i);
    }
    random_device rd;
    mt19937 g(rd());
    shuffle(numeros.begin(), numeros.end(), g);
    
    return numeros;
}

vector<int> listaAleatoriaComRepeticao(int tamanho) {
    vector<int> numeros;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, tamanho - 1);

    for (int i = 0; i < tamanho; i++) {
        numeros.push_back(dist(gen));
    }

    return numeros;
}
