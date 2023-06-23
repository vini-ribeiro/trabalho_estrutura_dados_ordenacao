#pragma once
#ifndef MERGESORT_CPP
#define MERGESORT_CPP

template <typename T>
void combinar(T* vetor, int comeco, int meio, int fim)
{
    int com1 = comeco, com2 = meio + 1, comAux = 0, tamanho = fim - comeco + 1;
    int* vetAux = new int[tamanho];

    while (com1 <= meio && com2 <= fim) {
        if (vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while (com1 <= meio) {
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while (com2 <= fim) {
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for (comAux = comeco; comAux <= fim; comAux++) {
        vetor[comAux] = vetAux[comAux - comeco];
    }

    delete[] vetAux;
}

template <typename T>
void mergeSort(T* vetor, int inicio, int fim)
{
    if (inicio == fim)
        return;

    int meio = (inicio + fim) / 2;
    mergeSort(vetor, inicio, meio);
    mergeSort(vetor, meio + 1, fim);
    combinar(vetor, inicio, meio, fim);
}

template <typename T>
void mergeSort(T* vetor, int tamanho)
{
    mergeSort(vetor, 0, tamanho - 1);
}

#endif