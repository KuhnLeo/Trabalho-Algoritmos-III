#ifndef CALCULADORA_H
#define CALCULADORA_H

#include <vector>
#include <cmath>
#include <iomanip>

double valorMedia(std::vector<long long>& numeros);
double valorVariancia(double media, std::vector<long long>& numeros);
double desvioPadrao(double variancia);
double mediaIntervalo(double media, double desvio, std::vector<long long>& numeros);

#endif
