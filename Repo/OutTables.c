#include <stdio.h>
#include <stdlib.h>
#include "Measurement.h"
#include "ResultsFilling.h"
#include "OutTables.h"

void OutTableStart()//Процедура виводу початку таблиці
{
    printf("|-----------------|-----------|----------|---------------|\n");
    printf("|                 |  Ordered  |  Random  |  Backordered  |\n");
    printf("|-----------------|-----------|----------|---------------|\n");
}

void OutTableAlg1Vector(int *A, int N)//Процедура виводу результатів для вектору, який сортувався алгоритмом номер 1
{
    Alg1OrdVect(A,N);
    ordered=MeasurementProcessing();
    Alg1RandVect(A,N);
    random=MeasurementProcessing();
    Alg1BackVect(A,N);
    backordered=MeasurementProcessing();
    printf("|  Select1Vector  |%11.2f|%10.2f|%15.2f|\n",ordered,random,backordered);
    printf("|-----------------|-----------|----------|---------------|\n");
}

void OutTableAlg2Vector(int *A, int N)//Процедура виводу результатів для вектору, який сортувався алгоритмом номер 2
{
    Alg2OrdVect(A,N);
    ordered=MeasurementProcessing();
    Alg2RandVect(A,N);
    random=MeasurementProcessing();
    Alg2BackVect(A,N);
    backordered=MeasurementProcessing();
    printf("|  Select8Vector  |%11.2f|%10.2f|%15.2f|\n",ordered,random,backordered);
    printf("|-----------------|-----------|----------|---------------|\n");
}

void OutTableAlg3Vector(int *A,int N)//Процедура виводу результатів для вектору, який сортувався алгоритмом номер 3
{
    Alg3OrdVect(A,N);
    ordered=MeasurementProcessing();
    Alg3RandVect(A,N);
    random=MeasurementProcessing();
    Alg3BackVect(A,N);
    backordered=MeasurementProcessing();
    printf("|  Shell_1Vector  |%11.2f|%10.2f|%15.2f|\n",ordered,random,backordered);
    printf("|-----------------|-----------|----------|---------------|\n");
}

void OutTableAlg1(int ***A,int N,int M,int P)//Процедура виводу результатів для тривимірного масиву, який сортувався алгоритмом номер 1
{
    Alg1Ord(A,N,M,P);
    ordered=MeasurementProcessing();
    Alg1Rand(A,N,M,P);
    random=MeasurementProcessing();
    Alg1Back(A,N,M,P);
    backordered=MeasurementProcessing();
    printf("|  Select1        |%11.2f|%10.2f|%15.2f|\n",ordered,random,backordered);
    printf("|-----------------|-----------|----------|---------------|\n");
}

void OutTableAlg2(int ***A,int N,int M,int P)//Процедура виводу результатів для тривимірного масиву, який сортувався алгоритмом номер 2
{
    Alg2Ord(A,N,M,P);
    ordered=MeasurementProcessing();
    Alg2Rand(A,N,M,P);
    random=MeasurementProcessing();
    Alg2Back(A,N,M,P);
    backordered=MeasurementProcessing();
    printf("|  Select8        |%11.2f|%10.2f|%15.2f|\n",ordered,random,backordered);
    printf("|-----------------|-----------|----------|---------------|\n");
}

void OutTableAlg3(int ***A,int N,int M,int P)//Процедура виводу результатів для тривимірного масиву, який сортувався алгоритмом номер 3
{
    Alg3Ord(A,N,M,P);
    ordered=MeasurementProcessing();
    Alg3Rand(A,N,M,P);
    random=MeasurementProcessing();
    Alg3Back(A,N,M,P);
    backordered=MeasurementProcessing();
    printf("|  Shell_1        |%11.2f|%10.2f|%15.2f|\n",ordered,random,backordered);
    printf("|-----------------|-----------|----------|---------------|\n");
}
