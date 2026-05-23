#include <iostream>
#include <vector>
#include <chrono>

#include "listCreator.h"
#include "sortings.h"

using namespace std;

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
