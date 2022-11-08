#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ArrInitialization.h"

void InitOrderedArray(int ***Arr3D,int N,int M,int P)//Процедура, яка заповнює тривимірний масив впорядковано
{
    int number=1;//Значення поточного елемента
    for (int k=0; k<P; k++)
        for (int j=0; j<M; j++)
            for (int i=0; i<N; i++)
            {
                Arr3D[k][j][i]=number;
                number++;
            }
}

void InitRandomArray(int ***Arr3D,int N,int M,int P)//Процедура, яка заповнює тривимірний масив випадково
{
    srand(time(NULL));
    for (int k=0; k<P; k++)
        for (int j=0; j<M; j++)
            for (int i=0; i<N; i++)
                Arr3D[k][j][i] = rand() % (P*M*N);

}

void InitBackorderedArray(int ***Arr3D,int N,int M,int P)//Процедура, яка заповнює тривимірний масив обернено впорядковано
{
    int number = P*M*N-1;//Значення поточного елемента
    for (int k=0; k<P; k++)
        for (int j=0; j<M; j++)
            for (int i=0; i<N; i++)
            {
                Arr3D[k][j][i]=number;
                number--;
            }
}

void InitOrderedVector(int *Arr,int N)//Процедура, яка заповнює вектор впорядковано
{
    int number=1;//Значення поточного елемента
    for (int i=0; i<N; i++)
            {
                Arr[i]=number;
                number++;
            }
}

void InitRandomVector(int *Arr,int N)//Процедура, яка заповнює вектор випадково
{
    srand(time(NULL));
    for (int i=0; i<N; i++)
            Arr[i]=rand() % N;
}

void InitBackorderedVector(int *Arr,int N)//Процедура, яка заповнює вектор обернено
{
    int number=N-1;//Значення поточного елемента
    for (int i=0; i<N; i++)
            {
                Arr[i]=number;
                number--;
            }
}
