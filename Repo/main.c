#include <stdio.h>
#include <stdlib.h>
#include "OutTables.h"
#include "ArrInitialization.h"
#include "Algorithms.h"


void Vivid(int ***A,int N,int M,int P)//Допоміжна процедура для виводу тривимірного масива
{
    for(int k=0;k<P;k++)
    {
        printf("P = %d\n",k);
        for(int i=0;i<M;i++)
        {
            for(int j=0;j<N;j++)
            {
                printf(" %3.1d",A[k][i][j]);
            }
            printf("\n");
        }
        printf("\n\n\n");
    }
}

void VividVector(int *A,int N)//Допоміжна процедура для виводу вектора
{
    for(int j=0;j<N;j++)
        {
            printf(" %3.1d",A[j]);
        }
}

int main()//Головна функція
{
 int choise;//Змінна вибору пункту з меню
 int N=8,M=6,P=2;//Розміри вимірів масиву
 int VectorLength;//Розмір вектору

 while(1)
 {
 printf("Choose amount of Pereriz\n");
 scanf("%d",&P);
 printf("Ryadkiv\n");
 scanf("%d",&M);
 printf("Stovbciv\n");
 scanf("%d",&N);
 printf("Choose amount of elements in vector\n");
 scanf("%d",&VectorLength);
 int Vector[VectorLength];//Вектор
 //-------------------------------------------------
 int ***Arr3D;//Тривимірний масив
 Arr3D = (int***) malloc(P*sizeof(int**));
 for (int k=0; k<P; k++)
 { Arr3D[k] = (int**) malloc(M*sizeof(int*));
 for (int i=0; i<M; i++)
 Arr3D[k][i] = (int*) malloc(N*sizeof(int));
 }
 //--------------------------------------------------

 printf("Choose mode. 1 - Packet   2 - Individual   3 - Exit    4 - Debug\n");
 scanf("%d",&choise);
 switch(choise)
 {
 case 1:
    printf("P = %d     M = %d     N = %d\n",P,M,N);
    OutTableStart();
    OutTableAlg1Vector(Vector,VectorLength);
    OutTableAlg2Vector(Vector,VectorLength);
    OutTableAlg3Vector(Vector,VectorLength);
    OutTableAlg1(Arr3D,N,M,P);
    OutTableAlg2(Arr3D,N,M,P);
    OutTableAlg3(Arr3D,N,M,P);
    break;
 case 2:
     printf("Chose Algorithm. 1 - Select1    2 - Select8     3 - Shell_1\n");
     scanf("%d",&choise);
     switch(choise)
     {
     case 1:
        printf("Chose Type. 1 - Vector    2 - 3D Array    3 - Both\n");
        scanf("%d",&choise);
        switch(choise)
        {
        case 1:
            OutTableStart();
            OutTableAlg1Vector(Vector,VectorLength);
            break;
        case 2:
            OutTableStart();
            OutTableAlg1(Arr3D,N,M,P);
            break;
        case 3:
            OutTableStart();
            OutTableAlg1Vector(Vector,VectorLength);
            OutTableAlg1(Arr3D,N,M,P);
            break;
        default:
            printf("Sorry, wrong number.");
            break;
        }
        break;
     case 2:
        printf("Chose Type. 1 - Vector    2 - 3D Array    3 - Both\n");
        scanf("%d",&choise);
        switch(choise)
        {
        case 1:
            OutTableStart();
            OutTableAlg2Vector(Vector,VectorLength);
            break;
        case 2:
            OutTableStart();
            OutTableAlg2(Arr3D,N,M,P);
            break;
        case 3:
            OutTableStart();
            OutTableAlg2Vector(Vector,VectorLength);
            OutTableAlg2(Arr3D,N,M,P);
            break;
        default:
            printf("Sorry, wrong number.");
            break;
        }
        break;
     case 3:
        printf("Chose Type. 1 - Vector    2 - 3D Array    3 - Both\n");
        scanf("%d",&choise);
        switch(choise)
        {
        case 1:
            OutTableStart();
            OutTableAlg3Vector(Vector,VectorLength);
            break;
        case 2:
            OutTableStart();
            OutTableAlg3(Arr3D,N,M,P);
            break;
        case 3:
            OutTableStart();
            OutTableAlg3Vector(Vector,VectorLength);
            OutTableAlg3(Arr3D,N,M,P);
            break;
        default:
            printf("Sorry, wrong number.");
            break;
        }
        break;
     default:
         printf("Sorry, wrong number.");
        break;
     }
    break;
 case 3:
    //--------------------------------------------------
    for (int k=0; k<P; k++)
    {
        for (int i=0; i<M; i++)free(Arr3D[k][i]);
        free(Arr3D[k]);
    }
    free(Arr3D);
    return 0;
    break;
 case 4:
     printf("Ordered\n\n");


     InitOrderedVector(Vector,VectorLength);
     printf("Select1Vector Before\n");
     VividVector(Vector,VectorLength);
     Select1Vector(Vector,VectorLength);
     printf("\nAfter\n");
     VividVector(Vector,VectorLength);
     printf("\n\n\n\n");

     InitOrderedVector(Vector,VectorLength);
     printf("Select8Vector Before\n");
     VividVector(Vector,VectorLength);
     Select8Vector(Vector,VectorLength);
     printf("\nAfter\n");
     VividVector(Vector,VectorLength);
     printf("\n\n\n\n");

     InitOrderedVector(Vector,VectorLength);
     printf("Shell_1Vector Before\n");
     VividVector(Vector,VectorLength);
     Shell_1Vector(Vector,VectorLength);
     printf("\nAfter\n");
     VividVector(Vector,VectorLength);
     printf("\n\n\n\n");

     InitOrderedArray(Arr3D,N,M,P);
     printf("Select1 Before\n");
     Vivid(Arr3D,N,M,P);
     Select1(Arr3D,N,M,P);
     printf("\nAfter\n");
     Vivid(Arr3D,N,M,P);
     printf("\n\n\n\n");

     InitOrderedArray(Arr3D,N,M,P);
     printf("Select8 Before\n");
     Vivid(Arr3D,N,M,P);
     Select8(Arr3D,N,M,P);
     printf("\nAfter\n");
     Vivid(Arr3D,N,M,P);
     printf("\n\n\n\n");

     InitOrderedArray(Arr3D,N,M,P);
     printf("Shell_1 Before\n");
     Vivid(Arr3D,N,M,P);
     Shell_1(Arr3D,N,M,P);
     printf("\nAfter\n");
     Vivid(Arr3D,N,M,P);
     printf("\n\n\n\n");


     printf("Random\n\n");


     InitRandomVector(Vector,VectorLength);
     printf("Select1Vector Before\n");
     VividVector(Vector,VectorLength);
     Select1Vector(Vector,VectorLength);
     printf("\nAfter\n");
     VividVector(Vector,VectorLength);
     printf("\n\n\n\n");

     InitRandomVector(Vector,VectorLength);
     printf("Select8Vector Before\n");
     VividVector(Vector,VectorLength);
     Select8Vector(Vector,VectorLength);
     printf("\nAfter\n");
     VividVector(Vector,VectorLength);
     printf("\n\n\n\n");

     InitRandomVector(Vector,VectorLength);
     printf("Shell_1Vector Before\n");
     VividVector(Vector,VectorLength);
     Shell_1Vector(Vector,VectorLength);
     printf("\nAfter\n");
     VividVector(Vector,VectorLength);
     printf("\n\n\n\n");

     InitRandomArray(Arr3D,N,M,P);
     printf("Select1 Before\n");
     Vivid(Arr3D,N,M,P);
     Select1(Arr3D,N,M,P);
     printf("\nAfter\n");
     Vivid(Arr3D,N,M,P);
     printf("\n\n\n\n");

     InitRandomArray(Arr3D,N,M,P);
     printf("Select8 Before\n");
     Vivid(Arr3D,N,M,P);
     Select8(Arr3D,N,M,P);
     printf("\nAfter\n");
     Vivid(Arr3D,N,M,P);
     printf("\n\n\n\n");

     InitRandomArray(Arr3D,N,M,P);
     printf("Shell_1 Before\n");
     Vivid(Arr3D,N,M,P);
     Shell_1(Arr3D,N,M,P);
     printf("\nAfter\n");
     Vivid(Arr3D,N,M,P);
     printf("\n\n\n\n");


     printf("Backordered\n\n");


     InitBackorderedVector(Vector,VectorLength);
     printf("Select1Vector Before\n");
     VividVector(Vector,VectorLength);
     Select1Vector(Vector,VectorLength);
     printf("\nAfter\n");
     VividVector(Vector,VectorLength);
     printf("\n\n\n\n");

     InitBackorderedVector(Vector,VectorLength);
     printf("Select8Vector Before\n");
     VividVector(Vector,VectorLength);
     Select8Vector(Vector,VectorLength);
     printf("\nAfter\n");
     VividVector(Vector,VectorLength);
     printf("\n\n\n\n");

     InitBackorderedVector(Vector,VectorLength);
     printf("Shell_1Vector Before\n");
     VividVector(Vector,VectorLength);
     Shell_1Vector(Vector,VectorLength);
     printf("\nAfter\n");
     VividVector(Vector,VectorLength);
     printf("\n\n\n\n");

     InitBackorderedArray(Arr3D,N,M,P);
     printf("Select1 Before\n");
     Vivid(Arr3D,N,M,P);
     Select1(Arr3D,N,M,P);
     printf("\nAfter\n");
     Vivid(Arr3D,N,M,P);
     printf("\n\n\n\n");

     InitBackorderedArray(Arr3D,N,M,P);
     printf("Select8 Before\n");
     Vivid(Arr3D,N,M,P);
     Select8(Arr3D,N,M,P);
     printf("\nAfter\n");
     Vivid(Arr3D,N,M,P);
     printf("\n\n\n\n");

     InitBackorderedArray(Arr3D,N,M,P);
     printf("Shell_1 Before\n");
     Vivid(Arr3D,N,M,P);
     Shell_1(Arr3D,N,M,P);
     printf("\nAfter\n");
     Vivid(Arr3D,N,M,P);
     printf("\n\n\n\n");
    break;
 default:
     printf("Sorry, wrong number.");
    break;
 }
    for (int k=0; k<P; k++)
    {
        for (int i=0; i<M; i++)free(Arr3D[k][i]);
        free(Arr3D[k]);
    }
    free(Arr3D);
 }

}
