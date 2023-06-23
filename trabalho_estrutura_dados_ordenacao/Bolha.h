#pragma once
#ifndef BOLHA_CPP
#define BOLHA_CPP

void bolha(int* vetor, const int TAM)
{
    int i, j, aux;
    bool troca;
    for (i = 0; i < TAM - 1; i++) {
        troca = false;
        for (j = 0; j < TAM - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
                troca = true;
            }
        }
        if (troca == false)
            break;
    }
}

#endif