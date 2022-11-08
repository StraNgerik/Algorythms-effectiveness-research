#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Algorithms.h"

clock_t Select1Vector(int *A, int N)
{
 int Min, imin;
 clock_t time_start, time_stop;
 time_start = clock();
 for(int s=0; s<N-1; s++){
 Min=A[s]; imin=s;
 for(int i=s+1; i<N; i++)
 if (A[i]<Min){
 Min=A[i];
 imin=i;
 }
 A[imin]=A[s];
 A[s]=Min;
 }
 time_stop = clock();
 return time_stop - time_start;
}

clock_t Select8Vector(int *A, int N)
{
 int L, R, imin, imax, tmp;
 clock_t time_start, time_stop;
 time_start = clock();
 L=0; R=N-1;
 while (L<R){
 imin=L; imax=L;
 for(int i=L+1; i<R+1; i++)
 if (A[i]<A[imin]) imin=i;
 else
 if (A[i]>A[imax]) imax=i;
 if (imin!=L) {
 tmp=A[imin];
 A[imin]=A[L];
 A[L]=tmp;
 }
 if (imax!=R)
 {
    if (imax==L) {
 tmp=A[imin];
 A[imin]=A[R];
 A[R]=tmp;
 }
 else {
 tmp=A[imax];
 A[imax]=A[R];
 A[R]=tmp;
 }
 }

 L=L+1; R=R-1;
 }
 time_stop = clock();
 return time_stop - time_start;
}

clock_t Shell_1Vector(int *A, int N)
{
 int Elem, t, j, k;
 clock_t time_start, time_stop;
 time_start = clock();
 if (N<4) t=1;
 else t=(int)log2f((float)N)-1;
 int Stages[t];
 Stages[t-1]=1;
 for (int i=t-2; i>=0; i--)
 Stages[i]=2*Stages[i+1]+1;
 for (int p=0; p<t; p++){
 k=Stages[p];
 for (int i=k; i<N; i++){
 Elem=A[i];
 j=i;
 while (j>=k && Elem<A[j-k]) {
 A[j]=A[j-k];
 j=j-k;
 }
 A[j]=Elem;
 }
 }
 time_stop = clock();
 return time_stop - time_start;
}

clock_t Select1(int ***A, int N, int M, int P)//Функція, яка виконує сортування методом вибору
{
 int Min, imin, Buffer;

 clock_t time_start, time_stop;
 time_start = clock();

 for(int PerCount=0;PerCount<P;PerCount++)
 {
     for(int s=0; s<N-1; s++)
    {
        Min=A[PerCount][0][s]; imin=s;
        for(int i=s+1; i<N; i++)
        {
            if (A[PerCount][0][i]<Min)
            {
                Min=A[PerCount][0][i];
                imin=i;
            }
        }
        A[PerCount][0][imin]=A[PerCount][0][s];
        A[PerCount][0][s]=Min;
        for(int RyadCount=1;RyadCount<M;RyadCount++)
        {
            Buffer=A[PerCount][RyadCount][imin];
            A[PerCount][RyadCount][imin]=A[PerCount][RyadCount][s];
            A[PerCount][RyadCount][s]=Buffer;
        }
    }
 }



 time_stop = clock();
 return time_stop - time_start;
}


clock_t Select8(int ***A, int N, int M,int P)//Функція, яка виконує сортування методом вибору 8
{
 int L, R, imin, imax, tmp;
 clock_t time_start, time_stop;
 time_start = clock();

 for(int PerCount=0;PerCount<P;PerCount++)
 {
 L=0; R=N-1;
 while (L<R)
 {
    imin=L; imax=L;
    for(int i=L+1; i<R+1; i++)
    {
        if (A[PerCount][0][i]<A[PerCount][0][imin]) imin=i;
        else
            if (A[PerCount][0][i]>A[PerCount][0][imax]) imax=i;

    }
    if (imin!=L)
        {
            tmp=A[PerCount][0][imin];
            A[PerCount][0][imin]=A[PerCount][0][L];
            A[PerCount][0][L]=tmp;
            for(int RyadCount=1;RyadCount<M;RyadCount++)
            {
                tmp=A[PerCount][RyadCount][imin];
                A[PerCount][RyadCount][imin]=A[PerCount][RyadCount][L];
                A[PerCount][RyadCount][L]=tmp;
            }
        }
    if (imax!=R)
    {
      if (imax==L)
        {
            tmp=A[PerCount][0][imin];
            A[PerCount][0][imin]=A[PerCount][0][R];
            A[PerCount][0][R]=tmp;
            for(int RyadCount=1;RyadCount<M;RyadCount++)
            {
                tmp=A[PerCount][RyadCount][imin];
                A[PerCount][RyadCount][imin]=A[PerCount][RyadCount][R];
                A[PerCount][RyadCount][R]=tmp;
            }
        }
        else
        {
            tmp=A[PerCount][0][imax];
            A[PerCount][0][imax]=A[PerCount][0][R];
            A[PerCount][0][R]=tmp;
            for(int RyadCount=1;RyadCount<M;RyadCount++)
            {
                tmp=A[PerCount][RyadCount][imax];
                A[PerCount][RyadCount][imax]=A[PerCount][RyadCount][R];
                A[PerCount][RyadCount][R]=tmp;
            }
        }
    }


    L=L+1; R=R-1;
 }
 }
 time_stop = clock();
 return time_stop - time_start;
}

clock_t Shell_1(int ***A, int N, int M, int P)//Функція, яка виконує сортування методом Шелла
{

 int Elem, t, j, k;
 int Buffer[M-1];
 clock_t time_start, time_stop;
 time_start = clock();

 for(int PerCount=0;PerCount<P;PerCount++)
 {
 if (N<4) t=1;
 else t=(int)log2f((float)N)-1;
 int Stages[t];
 Stages[t-1]=1;

 for (int i=t-2; i>=0; i--)
 Stages[i]=2*Stages[i+1]+1;

 for (int p=0; p<t; p++)
 {
        k=Stages[p];
        for (int i=k; i<N; i++)
        {
                Elem=A[PerCount][0][i];
                for(int RyadCount=1;RyadCount<M;RyadCount++)
                {
                    Buffer[RyadCount-1]=A[PerCount][RyadCount][i];
                }
                j=i;
                while (j>=k && Elem<A[PerCount][0][j-k])
                {
                        A[PerCount][0][j]=A[PerCount][0][j-k];
                        for(int RyadCount=1;RyadCount<M;RyadCount++)
                        {
                            A[PerCount][RyadCount][j]=A[PerCount][RyadCount][j-k];
                        }
                        j=j-k;
                }
                A[PerCount][0][j]=Elem;
                for(int RyadCount=1;RyadCount<M;RyadCount++)
                {
                    A[PerCount][RyadCount][j]=Buffer[RyadCount-1];
                }
        }
 }
 }
 time_stop = clock();
 return time_stop - time_start;
}
