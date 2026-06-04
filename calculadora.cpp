#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
/* Essa biblioteca usa uma função de formatação setprecision, que mantém
o valor total da variável mas mostra ela em apenas 2 casas decimais */

#include "calculadora.h"

using namespace std;

double valorMedia(vector<long long>& numeros) {
    double total = 0;
    for(int i=0; i<numeros.size(); i++) {
        total += numeros[i];
    }
    return total / numeros.size();
}

double valorVariancia(double media, vector<long long>& numeros) {
    double variancia = 0;
    for(int i=0; i<numeros.size(); i++) {
        variancia += pow(numeros[i] - media, 2);
    }
    return variancia / (numeros.size() - 1);
}

double desvioPadrao(double variancia) {
    return sqrt(variancia);
}

double mediaIntervalo(double media, double desvio, vector<long long>& numeros) {
    double limiteInferior = media - desvio;
    double limiteSuperior = media + desvio;

    double soma = 0;
    int quantidade = 0;

    for (long long numero : numeros) {
        if (numero >= limiteInferior && numero <= limiteSuperior) {
            soma += numero;
            quantidade++;
        }
    }

    if (quantidade == 0) {
        return 0;
    }
    return soma / quantidade;
}
