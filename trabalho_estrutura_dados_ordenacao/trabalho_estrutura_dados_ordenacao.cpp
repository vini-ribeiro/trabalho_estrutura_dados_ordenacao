#include "Bolha.h"
#include "Insercao.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "Selection.h"
#include "ShellSort.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

/// Entidade matriz
template <typename T>
struct Matriz {
    T** dado;
};

/// cria efetivamente a matriz
template <typename T>
void inicializarMatriz(Matriz<T>& m, const int tamanhoLinhas, const int tamanhoColunas)
{
    m.dado = new T*[tamanhoLinhas];
    for (int i = 0; i < tamanhoLinhas; i++) {
        m.dado[i] = new T[tamanhoColunas];
    }
}

enum AlgoritmosEnumeracao {
    Bolha = 0,
    Insercao,
    MergeSort,
    QuickSort,
    Selecao,
    ShellSort
};

void preencherVetorCrescente(int* vetor, const int TAM)
{
    for (int i = 0; i < TAM; i++) {
        vetor[i] = i;
    }
}

void preencherVetorDecrescente(int* vetor, const int TAM)
{
    for (int i = 0; i < TAM; i++) {
        vetor[i] = TAM - 1 - i;
    }
}

void preencherVetorAleatoriamente(int* vetor, const int TAM)
{
    for (int i = 0; i < TAM; i++) {
        // vetor[i] = rand() % INT_MAX;
        vetor[i] = rand() % (TAM);
    }
}

int entradaDeDados(string rotulo)
{
    int valor;
    bool valorInvalido = true;
    do {
        try {
            cout << rotulo << ": ";
            cin >> valor;
            if (valor < 1)
                throw "Valor invalido";
            valorInvalido = false;
        } catch (char const* msg) {
            cout << msg << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
    } while (valorInvalido);

    return valor;
}

template <typename T>
void printarVetor(T* vetor, const int tamanhoVetor)
{
    for (int i = 0; i < tamanhoVetor; i++) {
        cout << setw(5) << vetor[i];
    }
}

void copiarVetor(int* vetorOrigem, int* vetorDestino, const int tamanho)
{
    for (int i = 0; i < tamanho; i++) {
        vetorDestino[i] = vetorOrigem[i];
    }
}

/// Testando para o Bolha
double testarBolha(int* vetor, const int tamanho, const int quantidadeTestes)
{
    int* vetorCopia = new int[tamanho];
    clock_t inicio = clock(), fim = clock();
    clock_t somatorio = 0;

    for (int i = 0; i < quantidadeTestes; i++) {
        copiarVetor(vetor, vetorCopia, tamanho);
        cout << "\tTeste " << i + 1 << " comecou...";
        inicio = clock();
        bolha(vetorCopia, tamanho);
        fim = clock();
        cout << " Terminou"<<endl;
        somatorio += (fim - inicio);
    }
    delete[] vetorCopia;
    return (double)(somatorio / quantidadeTestes);
}

/// Testando para o Insercao
double testarInsercao(int* vetor, const int tamanho, const int quantidadeTestes)
{
    int* vetorCopia = new int[tamanho];
    clock_t inicio = clock(), fim = clock();
    clock_t somatorio = 0;

    for (int i = 0; i < quantidadeTestes; i++) {
        copiarVetor(vetor, vetorCopia, tamanho);
        cout << "\tTeste " << i + 1 << " comecou...";
        inicio = clock();
        insercao(vetorCopia, tamanho);
        fim = clock();
        cout << " Terminou"<<endl;
        somatorio += (fim - inicio);
    }
    delete[] vetorCopia;
    return (double)(somatorio / quantidadeTestes);
}

/// Testando para o MergeSort
double testarMergeSort(int* vetor, const int tamanho, const int quantidadeTestes)
{
    int* vetorCopia = new int[tamanho];
    clock_t inicio = clock(), fim = clock();
    clock_t somatorio = 0;

    for (int i = 0; i < quantidadeTestes; i++) {
        copiarVetor(vetor, vetorCopia, tamanho);
        cout << "\tTeste " << i + 1 << " comecou...";
        inicio = clock();
        mergeSort(vetorCopia, tamanho);
        fim = clock();
        cout << " Terminou"<<endl;
        somatorio += (fim - inicio);
    }
    delete[] vetorCopia;
    return (double)(somatorio / quantidadeTestes);
}

/// Testando para o QuickSort
double testarQuickSort(int* vetor, const int tamanho, const int quantidadeTestes)
{
    int* vetorCopia = new int[tamanho];
    clock_t inicio = clock(), fim = clock();
    clock_t somatorio = 0;

    for (int i = 0; i < quantidadeTestes; i++) {
        copiarVetor(vetor, vetorCopia, tamanho);
        cout << "\tTeste " << i + 1 << " comecou...";
        inicio = clock();
        quickSort(vetorCopia, tamanho);
        fim = clock();
        cout << " Terminou"<<endl;
        somatorio += (fim - inicio);
    }
    delete[] vetorCopia;
    return (double)(somatorio / quantidadeTestes);
}

/// Testando para o Selecao
double testarSelecao(int* vetor, const int tamanho, const int quantidadeTestes)
{
    int* vetorCopia = new int[tamanho];
    clock_t inicio = clock(), fim = clock();
    clock_t somatorio = 0;

    for (int i = 0; i < quantidadeTestes; i++) {
        copiarVetor(vetor, vetorCopia, tamanho);
        cout << "\tTeste " << i + 1 << " comecou...";
        inicio = clock();
        shellSort(vetorCopia, tamanho);
        fim = clock();
        cout << " Terminou"<<endl;
        somatorio += (fim - inicio);
    }
    delete[] vetorCopia;
    return (double)(somatorio / quantidadeTestes);
}

/// Testando para o ShellSort
double testarShellSort(int* vetor, const int tamanho, const int quantidadeTestes)
{
    int* vetorCopia = new int[tamanho];
    clock_t inicio = clock(), fim = clock();
    clock_t somatorio = 0;

    for (int i = 0; i < quantidadeTestes; i++) {
        copiarVetor(vetor, vetorCopia, tamanho);
        cout << "\tTeste " << i + 1 << " comecou...";
        inicio = clock();
        shellSort(vetorCopia, tamanho);
        fim = clock();
        cout << " Terminou"<<endl;
        somatorio += (fim - inicio);
    }
    delete[] vetorCopia;
    return (double)(somatorio / quantidadeTestes);
}

int main()
{
    srand(time(0));
    const int quantidadeDeVetores = entradaDeDados("Insira a quantidade de vetores");
    const int tamanhoVetor = entradaDeDados("Insira o tamanho do vetor");
    const int quantidadeDeTestes = entradaDeDados("Insira a quantidade de testes");

    Matriz<int> vetores;
    Matriz<double> resultados;

    // vetor original (cada linha eh um vetor e cada coluna eh um elemento de um vetor)
    inicializarMatriz(vetores, quantidadeDeVetores, tamanhoVetor);
    // vetor com os resultados (cada linha eh um algoritmo e cada coluna eh um resultado)
    inicializarMatriz(resultados, 6, quantidadeDeVetores);

    preencherVetorCrescente(vetores.dado[0], tamanhoVetor);
    preencherVetorDecrescente(vetores.dado[1], tamanhoVetor);

    for (int i = 2; i < quantidadeDeVetores; i++) { // preenche os vetores que nao sao oredenados (asc e desc)
        preencherVetorAleatoriamente(vetores.dado[i], tamanhoVetor);
    }

    /*
    for (int i = 0; i < quantidadeDeVetores; i++) {
        printarVetor(vetores.dado[i], tamanhoVetor);
        cout << endl;
    }
    */

    cout << "Processando os dados..." << endl;
    for (int i = 0; i < quantidadeDeVetores; i++) {
        cout << "Vetor " << i + 1 << " comecou:\nBolha:" << endl;
        resultados.dado[Bolha][i] = testarBolha(vetores.dado[i], tamanhoVetor, quantidadeDeTestes) / 1000.0;
        cout << "Insercao:" << endl;
        resultados.dado[Insercao][i] = testarInsercao(vetores.dado[i], tamanhoVetor, quantidadeDeTestes) / 1000.0;
        cout << "MergeSort:" << endl;
        resultados.dado[MergeSort][i] = testarMergeSort(vetores.dado[i], tamanhoVetor, quantidadeDeTestes) / 1000.0;
        cout << "QuickSort:" << endl;
        resultados.dado[QuickSort][i] = testarQuickSort(vetores.dado[i], tamanhoVetor, quantidadeDeTestes) / 1000.0;
        cout << "Selecao:" << endl;
        resultados.dado[Selecao][i] = testarSelecao(vetores.dado[i], tamanhoVetor, quantidadeDeTestes) / 1000.0;
        cout << "ShellSort:" << endl;
        resultados.dado[ShellSort][i] = testarShellSort(vetores.dado[i], tamanhoVetor, quantidadeDeTestes) / 1000.0;
        cout << "Terminou\n\n" << endl;
    }
    cout << "Concluido!" << endl;

    const char* nomeAlgoritmos[] = { "Bolha", "Insercao", "MergeSort", "QuickSort", "Selection", "ShellSort" };
    /*
    cout << "\n\n";
    cout << setw(10) << left << "Casos"
         << setw(15) << left << nomeAlgoritmos[Bolha]
         << setw(15) << left << nomeAlgoritmos[Insercao]
         << setw(15) << left << nomeAlgoritmos[MergeSort]
         << setw(15) << left << nomeAlgoritmos[QuickSort]
         << setw(15) << left << nomeAlgoritmos[Selecao]
         << setw(15) << left << nomeAlgoritmos[ShellSort] << "\n";

    for (int i = 0; i < quantidadeDeVetores; i++) {
        if (i == 0)
            cout << setw(10) << left << "Melhor: ";
        else if (i == 1)
            cout << setw(10) << left << "Pior  : ";
        else
            cout << setw(10) << left << "Medio : ";
        for (int j = 0; j < 6; j++) {
            cout << setw(15) << resultados.dado[j][i];
        }
        cout << "\n";
    }
    */

    ofstream arquivo;
    arquivo.open("media_resultados.txt", ios::app);
    if (!arquivo.is_open()) {
        cout << "Arquivo de gravacao nao pode ser aberto." << endl;
        return 0;
    }

    arquivo << "\n--------------------------------------------------------------------------------------------------"
            << "\nInsira a quantidade de vetores: " << quantidadeDeVetores
            << "\nInsira o tamanho do vetor: "<<tamanhoVetor
            << "\nInsira a quantidade de testes: " << quantidadeDeTestes << "\n\n";

    arquivo << setw(10) << left << "     "
            << setw(15) << left << nomeAlgoritmos[Bolha]
            << setw(15) << left << nomeAlgoritmos[Insercao]
            << setw(15) << left << nomeAlgoritmos[MergeSort]
            << setw(15) << left << nomeAlgoritmos[QuickSort]
            << setw(15) << left << nomeAlgoritmos[Selecao]
            << setw(15) << left << nomeAlgoritmos[ShellSort] << "\n";

    for (int i = 0; i < quantidadeDeVetores; i++) {
        if (i == 0)
            arquivo << setw(10) << left << "Melhor: ";
        else if (i == 1)
            arquivo << setw(10) << left << "Pior  : ";
        else
            arquivo << setw(10) << left << "Medio : ";
        for (int j = 0; j < 6; j++) {
            arquivo << setw(15) << resultados.dado[j][i];
        }
        arquivo << "\n";
    }
    arquivo << "\n";
    arquivo.close();

    return 0;
}