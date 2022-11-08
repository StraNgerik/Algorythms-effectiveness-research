#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ResultsFilling.h"
#include "Measurement.h"
#include "ArrInitialization.h"
#include "Algorithms.h"

void Alg1Ord(int ***A,int N,int M,int P)//Процедура заповнення масиву результатів вимірів для впорядкованого тривимірного масива, який сортувався алгоритмом прямої вставки
{
    for(int i=0;i<measurements_number;i++)
    {
        InitOrderedArray(A,N,M,P);
        Res[i]=Select1(A,N,M,P);
    }
}

void Alg1Rand(int ***A,int N,int M,int P)//Процедура заповнення масиву результатів вимірів для випадкового тривимірного масива, який сортувався алгоритмом прямої вставки
{
    for(int i=0;i<measurements_number;i++)
    {
        InitRandomArray(A,N,M,P);
        Res[i]=Select1(A,N,M,P);
    }
}

void Alg1Back(int ***A,int N,int M,int P)//Процедура заповнення масиву результатів вимірів для обернено впорядкованого тривимірного масива, який сортувався алгоритмом прямої вставки
{
    for(int i=0;i<measurements_number;i++)
    {
        InitBackorderedArray(A,N,M,P);
        Res[i]=Select1(A,N,M,P);
    }
}

void Alg2Ord(int ***A,int N,int M,int P)//Процедура заповнення масиву результатів вимірів для впорядкованого тривимірного масива, який сортувався алгоритмом вставки номер 8
{
    for(int i=0;i<measurements_number;i++)
    {
        InitOrderedArray(A,N,M,P);
        Res[i]=Select8(A,N,M,P);
    }
}

void Alg2Rand(int ***A,int N,int M,int P)//Процедура заповнення масиву результатів вимірів для випадкового тривимірного масива, який сортувався алгоритмом вставки номер 8
{
    for(int i=0;i<measurements_number;i++)
    {
        InitRandomArray(A,N,M,P);
        Res[i]=Select8(A,N,M,P);
    }
}

void Alg2Back(int ***A,int N,int M,int P)//Процедура заповнення масиву результатів вимірів для обернено впорядкованого тривимірного масива, який сортувався алгоритмом вставки номер 8
{
    for(int i=0;i<measurements_number;i++)
    {
        InitBackorderedArray(A,N,M,P);
        Res[i]=Select8(A,N,M,P);
    }
}

void Alg3Ord(int ***A,int N,int M,int P)//Процедура заповнення масиву результатів вимірів для впорядкованого тривимірного масива, який сортувався алгоритмом Шелла
{
    for(int i=0;i<measurements_number;i++)
    {
        InitOrderedArray(A,N,M,P);
        Res[i]=Shell_1(A,N,M,P);
    }
}

void Alg3Rand(int ***A,int N,int M,int P)//Процедура заповнення масиву результатів вимірів для випадкового тривимірного масива, який сортувався алгоритмом Шелла
{
    for(int i=0;i<measurements_number;i++)
    {
        InitRandomArray(A,N,M,P);
        Res[i]=Shell_1(A,N,M,P);
    }
}

void Alg3Back(int ***A,int N,int M,int P)//Процедура заповнення масиву результатів вимірів для обернено впорядкованого тривимірного масива, який сортувався алгоритмом Шелла
{
    for(int i=0;i<measurements_number;i++)
    {
        InitBackorderedArray(A,N,M,P);
        Res[i]=Shell_1(A,N,M,P);
    }
}



void Alg1OrdVect(int *A,int N)//Процедура заповнення масиву результатів вимірів для впорядкованого вектора, який сортувався алгоритмом прямої вставки
{
    for(int i=0;i<measurements_number;i++)
    {
        InitOrderedVector(A,N);
        Res[i]=Select1Vector(A,N);
    }
}

void Alg1RandVect(int *A,int N)//Процедура заповнення масиву результатів вимірів для випадкового вектора, який сортувався алгоритмом прямої вставки
{
    for(int i=0;i<measurements_number;i++)
    {
        InitRandomVector(A,N);
        Res[i]=Select1Vector(A,N);
    }
}

void Alg1BackVect(int *A,int N)//Процедура заповнення масиву результатів вимірів для обернено впорядкованого вектора, який сортувався алгоритмом прямої вставки
{
    for(int i=0;i<measurements_number;i++)
    {
        InitBackorderedVector(A,N);
        Res[i]=Select1Vector(A,N);
    }
}

void Alg2OrdVect(int *A,int N)//Процедура заповнення масиву результатів вимірів для впорядкованого вектора, який сортувався алгоритмом вставки номер 8
{
    for(int i=0;i<measurements_number;i++)
    {
        InitOrderedVector(A,N);
        Res[i]=Select8Vector(A,N);
    }
}

void Alg2RandVect(int *A,int N)//Процедура заповнення масиву результатів вимірів для випадкового вектора, який сортувався алгоритмом вставки номер 8
{
    for(int i=0;i<measurements_number;i++)
    {
        InitRandomVector(A,N);
        Res[i]=Select8Vector(A,N);
    }
}

void Alg2BackVect(int *A,int N)//Процедура заповнення масиву результатів вимірів для обернено впорядкованого вектора, який сортувався алгоритмом вставки номер 8
{
    for(int i=0;i<measurements_number;i++)
    {
        InitBackorderedVector(A,N);
        Res[i]=Select8Vector(A,N);
    }
}

void Alg3OrdVect(int *A,int N)//Процедура заповнення масиву результатів вимірів для впорядкованого вектора, який сортувався алгоритмом Шелла
{
    for(int i=0;i<measurements_number;i++)
    {
        InitOrderedVector(A,N);
        Res[i]=Shell_1Vector(A,N);
    }
}

void Alg3RandVect(int *A,int N)//Процедура заповнення масиву результатів вимірів для випадкового вектора, який сортувався алгоритмом Шелла
{
    for(int i=0;i<measurements_number;i++)
    {
        InitRandomVector(A,N);
        Res[i]=Shell_1Vector(A,N);
    }
}

void Alg3BackVect(int *A,int N)//Процедура заповнення масиву результатів вимірів для обернено впорядкованого вектора, який сортувався алгоритмом Шелла
{
    for(int i=0;i<measurements_number;i++)
    {
        InitBackorderedVector(A,N);
        Res[i]=Shell_1Vector(A,N);
    }
}
