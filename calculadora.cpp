#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
/* Essa biblioteca usa uma função de formatação setprecision, que mantém
o valor total da variável mas mostra ela em apenas 2 casas decimais */

using namespace std;

float valorMedia(vector<int>& numeros) {
    float total = 0;
    for(int i=0; i<numeros.size(); i++) {
        total += numeros[i];
    }
    return total / numeros.size();
}

double valorVariancia(float media, vector<int>& numeros) {
    double variancia = 0;
    for(int i=0; i<numeros.size(); i++) {
        variancia += pow(numeros[i] - media, 2);
    }
    return variancia / (numeros.size() - 1);
}

float desvioPadrao(float variancia) {
    return sqrt(variancia);
}



int main () {

    vector<int> numeros = {};

    cout << "****************************************" << endl;
    cout << "********* CALCULADORA DE DADOS *********" << endl;
    cout << "****************************************" << endl << endl;

    cout << "Digite os números: ";
    for (int i=0; i<10; i++) {
        int numero;
        cin >> numero;
        numeros.push_back(numero);
    }
    cout << endl << endl;


    cout << fixed << setprecision(2);

    float media = valorMedia(numeros);
    double variancia = valorVariancia(media, numeros);
    float desvio = desvioPadrao(variancia);

    cout << "Média: " << media << endl;
    cout << "Variância: " << variancia << endl;
    cout << "Desvio padrão: " << desvio;

    return 0;
}