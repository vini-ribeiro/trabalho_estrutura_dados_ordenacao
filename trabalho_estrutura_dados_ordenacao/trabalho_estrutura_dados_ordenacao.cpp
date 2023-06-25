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

/// matriz
template <typename T>
struct Matriz {
    T** dado;
};

/// inicializa a matriz
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

/// preenche o vetor com numeros em ordem decrescente
void preencherVetorCrescente(int* vetor, const int TAM)
{
    for (int i = 0; i < TAM; i++) {
        vetor[i] = i;
    }
}

/// preenche o vetor com numeros em ordem decrescente
void preencherVetorDecrescente(int* vetor, const int TAM)
{
    for (int i = 0; i < TAM; i++) {
        vetor[i] = TAM - 1 - i;
    }
}

/// preenche o vetor com numeros aleatorios
void preencherVetorAleatoriamente(int* vetor, const int TAM)
{
    for (int i = 0; i < TAM; i++) {
        // vetor[i] = rand() % INT_MAX;
        vetor[i] = rand() % (TAM);
    }
}

/// faz a entrada dos dados
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

/// passa tdos os valores de um vetor para outro
void copiarVetor(int* vetorOrigem, int* vetorDestino, const int tamanho)
{
    for (int i = 0; i < tamanho; i++) {
        vetorDestino[i] = vetorOrigem[i];
    }
}

/// Testa o Bolha
double testarBolha(int* vetor, const int tamanho, const int quantidadeTestes)
{
    int* vetorCopia = new int[tamanho]; /// vetor alocado para o teste
    clock_t inicio = clock(), fim = clock();
    clock_t somatorio = 0;

    for (int i = 0; i < quantidadeTestes; i++) {
        copiarVetor(vetor, vetorCopia, tamanho); /// a cada iteracao o vetor eh resetado para o original
        cout << "\tTeste " << i + 1 << " comecou...";
        inicio = clock(); /// pega o horario no inicio do teste
        bolha(vetorCopia, tamanho); /// chama a funcao para ordenar
        fim = clock(); /// pega o horario no final do teste
        cout << " Terminou"<<endl;
        somatorio += (fim - inicio); /// faz o calculo do intervalo de tempo e soma com os das iteracoes anteriores
    }
    delete[] vetorCopia; /// desaloca o vetor copia
    return (double)(somatorio / quantidadeTestes); /// calcula a media de tempo
}

/// Testa o Insercao (identico ao Bolha)
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

/// Testa o MergeSort (identico ao Bolha)
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

/// Testa o QuickSort (identico ao Bolha)
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

/// Testa o Selecao (identico ao Bolha)
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

/// Testa o ShellSort (identico ao Bolha)
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
    /// pega a quantidade de vetores, tamanho dos vetores e quantidade de testes
    const int quantidadeDeVetores = entradaDeDados("Insira a quantidade de vetores"); 
    const int tamanhoVetor = entradaDeDados("Insira o tamanho do vetor");
    const int quantidadeDeTestes = entradaDeDados("Insira a quantidade de testes");

    /// instancia uma matriz para armazenar os vetores e uma para os resultados (tempo dos testes)
    Matriz<int> vetores;
    Matriz<double> resultados;

    /// vetor original (cada linha eh um vetor e cada coluna eh um elemento de um vetor)
    inicializarMatriz(vetores, quantidadeDeVetores, tamanhoVetor);
    /// vetor com os resultados (cada linha eh um algoritmo e cada coluna eh um resultado)
    inicializarMatriz(resultados, 6, quantidadeDeVetores);

    /// preenche o primeiro vetor ja ordenado
    preencherVetorCrescente(vetores.dado[0], tamanhoVetor);
    /// preenche o segundo vetor ordenado de forma inversa
    preencherVetorDecrescente(vetores.dado[1], tamanhoVetor);

    /// o resto eh preenchido aleatoriamente
    for (int i = 2; i < quantidadeDeVetores; i++) { // preenche os vetores que nao sao oredenados (asc e desc)
        preencherVetorAleatoriamente(vetores.dado[i], tamanhoVetor);
    }

    /// chama as funcoes de teste de cada algoritmo e salva o resultado na matriz resultado
    cout << "Processando os dados..." << endl;
    for (int i = 0; i < quantidadeDeVetores; i++) {
        cout << "Vetor " << i + 1 << " comecou:\nBolha:" << endl;
        resultados.dado[Bolha][i] = testarBolha(vetores.dado[i], tamanhoVetor, quantidadeDeTestes) / 1000.0; /// divide por 1000 para transformar em segundos
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

    /// vetor com os nomes dos algoritmos de ordenacao
    const char* nomeAlgoritmos[] = { "Bolha", "Insercao", "MergeSort", "QuickSort", "Selection", "ShellSort" };
    
    cout << "\n\n";
    cout << setw(10) << left << "     "
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
    

    /// abre (ou cria caso nao exista) um arquivo para gravar os resultados
    ofstream arquivo;
    arquivo.open("resultados.txt", ios::app); /// escreve sempre no final do arquivo
    if (!arquivo.is_open()) {
        cout << "Arquivo de gravacao nao pode ser aberto." << endl;
        return 0;
    }

    /// escreve um cabecalho com as entradas do usuario
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

    /// escreve os resultados no arquivo
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
    arquivo.close(); /// fecha o arquivo 

    return 0;
}