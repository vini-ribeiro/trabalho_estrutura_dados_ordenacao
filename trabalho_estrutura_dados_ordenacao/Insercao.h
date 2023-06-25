#pragma once
#ifndef INSERCAO_CPP
#define INSERCAO_CPP

#include <iostream>

using namespace std;

void insercao(int* vetor, const int TAM)
{
    int chave, i;
    for (int j = 1; j < TAM; j++) {
        chave = vetor[j];
        i = j - 1;
        while (i >= 0 && vetor[i] > chave) {
            vetor[i + 1] = vetor[i];
            i--;
        }
        vetor[i + 1] = chave;
    }
}

#endif