#ifndef QUICKSORT_CPP
#define QUICKSORT_CPP

#include <iostream>

using namespace std;

template <typename T>
void QuickSort(T* vetor, int esq, int dir)
{
    int x, i, j, aux;
    i = esq;
    j = dir;
    x = vetor[(i + j) / 2];
    do {
        while (x > vetor[i])
            i = i + 1;
        while (x < vetor[j])
            j = j - 1;
        if (i <= j) {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i = i + 1;
            j = j - 1;
        }
    } while (i <= j);
    if (esq < j)
        QuickSort(vetor, esq, j);
    if (dir > i)
        QuickSort(vetor, i, dir);
}

template <typename T>
void QuickSort(T* vetor, int tamanho)
{
    QuickSort(vetor, 0, tamanho-1);
}

#endif