#include <iostream>
#include <vector>
#include <chrono>

#include "listCreators/listCreator.h"
#include "sortings/sortings.h"

using namespace std;

int main() {
    int var = 10;
    
    vector<int> numeros = listaAleatoriaComRepeticao(var);

    auto inicio = chrono::steady_clock::now();

    bubbleSort(numeros);

    auto fim = chrono::steady_clock::now();

    auto duracao = fim - inicio;
    auto duracaoNano = chrono::duration_cast<chrono::nanoseconds>(duracao);

    cout << "Tempo gasto para ordenar " << var << " números: " << duracaoNano.count() << " nanosegundos" << endl;
    
    return 0;
}
