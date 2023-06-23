#ifndef SHELLSORT_CPP
#define SHELLSORT_CPP

#include <iostream>

using namespace std;

template <typename T>
void ShellSort(T* vet, int TAM)
{
    int i, j, value;
    int gap = 1;
    while (gap < TAM) {
        gap = 3 * gap + 1;
    }
    while (gap > 1) {
        gap /= 3;
        for (i = gap; i < TAM; i++) {
            value = vet[i];
            j = i - gap;
            while (j >= 0 && value < vet[j]) {
                vet[j + gap] = vet[j];
                j -= gap;
            }
            vet[j + gap] = value;
        }
    }
}

#endif