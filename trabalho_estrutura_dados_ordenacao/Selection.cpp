#ifndef SELECTION_CPP
#define SELECTION_CPP

#include <iostream>

using namespace std;

template <typename T>
void Selecao(T* vetor, const int TAM)
{
    int pos_menor, temp;

    for (int i = 0; i < TAM - 1; i++) {
        pos_menor = i;
        for (int j = i + 1; j < TAM; j++) {
            if (vetor[j] < vetor[pos_menor])
                pos_menor = j;
        }
        temp = vetor[i];
        vetor[i] = vetor[pos_menor];
        vetor[pos_menor] = temp;
    }
}

#endif