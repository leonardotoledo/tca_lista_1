//-------------------------------------------------------------------------
//SORTING_ALGORITHMS.CPP
//-------------------------------------------------------------------------
//Implementa��o dos algoritmos de ordena��o de n n�meros visto em aula 
//(Sele��o, Mergesort, Quicksort e Inser��o). Para os valores n variando 
//entre 100, 1.000, 10.000, 100.000 e 1.000.000. Em que n precisa ser 
// modificado no in�cio do programa.
// Obs.: a ordena��o foi verificada. Entretanto este c�digo apenas coleta
// os tempos para a execu��o dos algor�timos
// -------------------------------------------------------------------------
// Universidade Federal de Alagoas - UFAL
// Centro de Tecnologia - CTEC
// Programa de P�s-Gradua��o em Engenharia Civil - PPGEC
// Laborat�rio de Computa��o Cient�fica e Visualiza��o - LCCV
// -------------------------------------------------------------------------
// Por: Themisson dos Santos Vasconcelos (themisson@gmail.com) e 
//      Leonardo Ferreira ()
// -------------------------------------------------------------------------
// Cria��o: 07/07/2020
// Vers�o:  08/07/2020
// -------------------------------------------------------------------------

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <chrono>

void random_numbers(int* numbers, int size);
void ascending_numbers(int* numbers, int size);
void descending_numbers(int* numbers, int size);
void getPointer(int* numbers, int* copy, int size);
void selection_sort(int* numbers, int size);
void merge_sort(int* numbers, int size);
void quick_sort(int* numbers, int r, int s);
void insertion_sort(int* numbers, int size);
void init(int* numbers, int n, int op);

//n varia entre: 100, 1000, 10000, 100000 e 1000000 n�meros
int n = 10000000;

int main() {
    //Ajustando impress�o em tela para a linguagem local
    setlocale(LC_ALL, "Portuguese");

    //Vetores com n�meros aleat�rios
    int* numbers1 = new int[n];
    random_numbers(numbers1, n);
    std::cout << "========== Vetor com n�meros aleat�rios ==========" << std::endl;
    
    //Aloca��o de mem�ria para a c�pia do ponteiro inicial
    int *copy1 = (int*)malloc(sizeof(numbers1)*n), * copy2 = (int*)malloc(sizeof(numbers1)*n),
        *copy3 = (int*)malloc(sizeof(numbers1)*n);
    
    //Fun��o para c�pia do ponteiro
    getPointer(numbers1, copy1, n);
    getPointer(numbers1, copy2, n);
    getPointer(numbers1, copy3, n);
            
    //vetor, size of vector, op
    init(numbers1, n, 1);   
    init(copy1, n, 2);
    init(copy2, n, 3);
    init(copy3, n, 4);
    
    //Vetores com n�meros crescentes
    int* numbers2 = new int[n];
    ascending_numbers(numbers2, n);
    std::cout << "========== Vetor com n�meros ascendentes ==========" << std::endl;
    //Aloca��o de mem�ria para a c�pia do ponteiro inicial
    int* copy4 = (int*)malloc(sizeof(numbers1)*n), *copy5 = (int*)malloc(sizeof(numbers1)*n),
        *copy6 = (int*)malloc(sizeof(numbers1)*n);
    
    //Fun��o para c�pia do ponteiro
    getPointer(numbers2, copy4, n);
    getPointer(numbers2, copy5, n);
    getPointer(numbers2, copy6, n);

    //vetor, size of vector, op
    init(numbers2, n, 1);
    init(copy4, n, 2);
    init(copy5, n, 3);
    init(copy6, n, 4);

    //Vetores com n�meros decrescentes
    int* numbers3 = new int[n];
    descending_numbers(numbers3, n);
    std::cout << "========== Vetor com n�meros descendentes ==========" << std::endl;
    
    //Aloca��o de mem�ria para a c�pia do ponteiro inicial
    int *copy7 = (int*)malloc(sizeof(numbers1)*n), *copy8 = (int*)malloc(sizeof(numbers1)*n),
        *copy9 = (int*)malloc(sizeof(numbers1)*n);
    
    //Fun��o para c�pia do ponteiro
    getPointer(numbers3, copy7, n);
    getPointer(numbers3, copy8, n);
    getPointer(numbers3, copy9, n);

    //vetor, size of vector, op
    init(numbers3, n, 1);
    init(copy7, n, 2);
    init(copy8, n, 3);
    init(copy9, n, 4);
    
    //liber��o de mem�ria alocada para os vetores
    delete numbers1;
    delete numbers2;
    delete numbers3;
    delete copy1;
    delete copy2;
    delete copy3;
    delete copy4;
    delete copy5;
    delete copy6;
    delete copy7;
    delete copy8;
    delete copy9;
 
    system("pause");
    return 0;
}

void init(int* numbers, int n, int op) {
    //Utilizado o if no lugar de case, pois o case n�o perrmite a utiliza��o da classe nativa std::chrono::steady_clock::
    if (op == 1) {

        std::cout << "--- Selection Sort ---" << std::endl;
        auto start = std::chrono::steady_clock::now();

        selection_sort(numbers, n);

        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsedTime = end - start;
        std::cout << "Tempo: " << elapsedTime.count() << std::endl;
        std::cout << std::endl;
    }
    else if (op == 2) {

        std::cout << "--- Merge Sort ---" << std::endl;
        auto start = std::chrono::steady_clock::now();

        merge_sort(numbers, n);

        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsedTime = end - start;
        std::cout << "Tempo: " << elapsedTime.count() << std::endl;
        std::cout << std::endl;
    }
    else if (op == 3) {

        std::cout << "--- Quick Sort ---" << std::endl;
        auto start = std::chrono::steady_clock::now();

        quick_sort(numbers, 0, n-1);

        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsedTime = end - start;
        std::cout << "Tempo: " << elapsedTime.count() << std::endl;
        std::cout << std::endl;
    }

    else if (op == 4) {
        std::cout << "--- Insertion Sort ---" << std::endl;
        auto start = std::chrono::steady_clock::now();

        insertion_sort(numbers, n);

        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsedTime = end - start;
        std::cout << "Tempo: " << elapsedTime.count() << std::endl;
        std::cout << std::endl;
    }
};


//Fun��o para copiar os valores de um ponteiro
void getPointer(int* numbers, int* copy, int size) {
    
    for (unsigned int i = 0; i != size; ++i) {
        copy[i] = numbers[i];
    }
};

//Fun��es para cria��o de vetores num�ricos
void random_numbers(int* numbers, int size)
{
    for (unsigned int i = 0; i != size; ++i)
        numbers[i] = (rand() % size + 1);
};

void ascending_numbers(int* numbers, int size)
{
    for (unsigned int i = 0; i != size; ++i)
        numbers[i] = i + 1;
};

void descending_numbers(int* numbers, int size)
{
    for (unsigned int i = 0; i != size; ++i)
        numbers[i] = size - i;
};

//Fun��es de ordena��o
void selection_sort(int* numbers, int size)
{
    int m = 0, aux = 0;

    for (unsigned int i = 0; i != size - 1; ++i)
    {
        m = i;

        for (unsigned int j = i + 1; j != size; ++j) {

            m = (numbers[j] < numbers[m]) ? m = j : m = m;
        }

        aux = numbers[i];
        numbers[i] = numbers[m];
        numbers[m] = aux;
    }
};

void merge_sort(int* numbers, int size)
{

    if (size < 2)
    {
        return;
    }
    else
    {
        int m = (int)(.5 * size);

        //Fazendo a aloca��o de mem�ria
        int* l = (int*)malloc(m * sizeof(numbers[0]));
        int* r = (int*)malloc((size - m) * sizeof(numbers[0]));

        //Copiando o vetor dividido para o �ndice 0
        memcpy(l, numbers, m * sizeof(numbers[0]));
        //Copiando o vetor dividido para o �ndice m
        memcpy(r, numbers + m, (size - m) * sizeof(numbers[0]));

        //Aplicando o merge sort recursivamente
        merge_sort(l, m);
        merge_sort(r, size - m);

        unsigned int i = 0, j = 0;

        for (unsigned int k = 0; k != size; ++k)
        {
            if (i == m)
            {
                numbers[k] = r[j];
                ++j;
            }
            else if (j == size - m)
            {
                numbers[k] = l[i];
                ++i;
            }
            else
            {
                if (l[i] < r[j])
                {
                    numbers[k] = l[i];
                    ++i;
                }
                else
                {
                    numbers[k] = r[j];
                    ++j;
                }
            }
        }

        free(l);
        free(r);
    }
};

void quick_sort(int* numbers, int left, int right)
{

    if (right <= left)
    {
        return;
    }
    else
    {
        // Inicializa��o das vari�veis
        int v = numbers[(int)(left+ right)/2], i = left, j = right, aux;

        while (j >= i)
        {
            while (numbers[i] < v && right > i)
            {
                ++i;
            }
            while (numbers[j] > v && j> left)
            {
                --j;
            }
            if (i <= j)
            {
                aux = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = aux;
                ++i;
                --j;
            }
        }

        if (j > left) {
            quick_sort(numbers, left, j);
        }
        if (i < right) {
            quick_sort(numbers, i, right);
        }
    }
};

void insertion_sort(int* numbers, int size)
{

    int j = 0, v = 0, aux = 0;

    for (unsigned int i = 1; i != size; ++i)
    {
        v = numbers[i];
        j = i;

        while (numbers[j - 1] > v && j > 0)
        {
            aux = numbers[j];
            numbers[j] = numbers[j - 1];
            numbers[j - 1] = aux;
            --j;
        }

        numbers[j] = v;
    }
};