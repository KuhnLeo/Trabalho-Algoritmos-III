#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <iomanip>

#include "listCreators/listCreator.h"
#include "sortings/sortings.h"
#include "output/calculadora.h"

using namespace std;

void executaSorting(int var, vector<int>& numeros){
    if (var == 0) {
        bubbleSort(numeros);
    } else if (var == 1) {
        insertionSort(numeros);
    } else if (var == 2) {
        selectionSort(numeros);
    } else if (var == 3) {
        heapSort(numeros);
    } else if (var == 4) {
        shellSort(numeros);
    } else if (var == 5) {
        mergeSort(numeros, 0, numeros.size() - 1);
    } else if (var == 6) {
        quickSort(numeros, 0, numeros.size() - 1);
    }
}

string qualSorting(int var){
    if (var == 0) {
        return "Bubble Sort";
    } else if (var == 1) {
        return "Insertion Sort" ;
    } else if (var == 2) {
        return "Selection Sort";
    } else if (var == 3) {
        return "Heap Sort";
    } else if (var == 4) {
        return "Shell Sort";
    } else if (var == 5) {
        return "Merge Sort";
    } else if (var == 6) {
        return "Quick Sort";
    }
    return "Erro na escolha de sorting";
}

int main() {

    cout << fixed << setprecision(2);


    for (int i = 7; i <= 16; i++) {                                 // executa para 128 a 65536

        int var = static_cast<int>(pow(2, i));                      // pow muda para double, com static cast fica int novamente

        vector<int> numerosOriginal = listaAleatoriaComRepeticao(var);           // cria o array do tamanho da vez

        for (int j = 0; j < 7; j++) {                                   // ajuda a determinar o sorting utilizado

            vector<long long> tempos;

            for (int k = 0; k < 10; k++) {                              // executa 10 vezes por sorting

                vector<int> numeros = numerosOriginal;

                auto inicio = chrono::steady_clock::now();

                executaSorting(j, numeros);                         // define o sorting a ser executado

                auto fim = chrono::steady_clock::now();

                auto duracao = fim - inicio;
                auto duracaoNano = chrono::duration_cast<chrono::nanoseconds>(duracao);

                tempos.push_back(duracaoNano.count());

            }
            double media = valorMedia(tempos);
            double variancia = valorVariancia(media, tempos);
            double desvio = desvioPadrao(variancia);
            double mediaFiltrada = mediaIntervalo(media, desvio, tempos);

            cout << "Tamanho do array: "
            << var << endl;
            cout << "Sorting utilizado: "
            << qualSorting(j) << endl;
            cout << "Media de valor: "
            << media
            << endl;
            cout << "Variância: "
            << variancia
            << endl;
            cout << "Desvio padrão: "
            << desvio
            << endl;
            cout << "Média filtrada: "
            << mediaFiltrada
            << endl << endl;
            
        }
    }
    
    return 0;
}
