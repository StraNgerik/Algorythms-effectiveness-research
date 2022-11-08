#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ArrInitialization.h"

void InitOrderedArray(int ***Arr3D,int N,int M,int P)//���������, ��� �������� ���������� ����� ������������
{
    int number=1;//�������� ��������� ��������
    for (int k=0; k<P; k++)
        for (int j=0; j<M; j++)
            for (int i=0; i<N; i++)
            {
                Arr3D[k][j][i]=number;
                number++;
            }
}

void InitRandomArray(int ***Arr3D,int N,int M,int P)//���������, ��� �������� ���������� ����� ���������
{
    srand(time(NULL));
    for (int k=0; k<P; k++)
        for (int j=0; j<M; j++)
            for (int i=0; i<N; i++)
                Arr3D[k][j][i] = rand() % (P*M*N);

}

void InitBackorderedArray(int ***Arr3D,int N,int M,int P)//���������, ��� �������� ���������� ����� �������� ������������
{
    int number = P*M*N-1;//�������� ��������� ��������
    for (int k=0; k<P; k++)
        for (int j=0; j<M; j++)
            for (int i=0; i<N; i++)
            {
                Arr3D[k][j][i]=number;
                number--;
            }
}

void InitOrderedVector(int *Arr,int N)//���������, ��� �������� ������ ������������
{
    int number=1;//�������� ��������� ��������
    for (int i=0; i<N; i++)
            {
                Arr[i]=number;
                number++;
            }
}

void InitRandomVector(int *Arr,int N)//���������, ��� �������� ������ ���������
{
    srand(time(NULL));
    for (int i=0; i<N; i++)
            Arr[i]=rand() % N;
}

void InitBackorderedVector(int *Arr,int N)//���������, ��� �������� ������ ��������
{
    int number=N-1;//�������� ��������� ��������
    for (int i=0; i<N; i++)
            {
                Arr[i]=number;
                number--;
            }
}
