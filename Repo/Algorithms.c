#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Algorithms.h"

clock_t Select1Vector(int *A, int N)//Функція, яка сортує вектор методом прямого вибору і повертає час який пішов на сортування
{
 int Min, imin;
 clock_t time_start, time_stop;
 time_start = clock();
 for(int s=0; s<N-1; s++)//Цикл, який йде по масиву, ставлячи мінімальні елементи в початок
 {
    Min=A[s]; imin=s;
    for(int i=s+1; i<N; i++)//Внутрішній цикл, який знаходить мінімальне значення, якщо воно виявилося не на першому місці
    {
        if (A[i]<Min)
        {
            Min=A[i];
            imin=i;
        }
    }
    A[imin]=A[s];//Заміна послідоовних елементів масиву на мінімальне за останній прохід циклу
    A[s]=Min;
 }
 time_stop = clock();
 return time_stop - time_start;
}

clock_t Select8Vector(int *A, int N)//Функція, яка сортує вектор методом вибору номер 8 і повертає час який пішов на сортування
{
 int L, R, imin, imax, tmp;
 clock_t time_start, time_stop;
 time_start = clock();
 L=0; R=N-1;
 while (L<R)//Головний цикл, виконується поки границі L і R не перетнуться або не зрівняються
 {
    imin=L; imax=L;
    for(int i=L+1; i<R+1; i++)//Цикл, який одночасно шукає мінімум та максимум на проміжку від L+1 до R
    {
        if (A[i]<A[imin]) imin=i;
        else
            if (A[i]>A[imax]) imax=i;
    }

    if (imin!=L) //Перевірка на те, чи є мінімальний елемент на правильному місці
    {
        tmp=A[imin];//Якщо це не так - відбувається перестановка мінімального
        A[imin]=A[L];//елементу на потрібне місце
        A[L]=tmp;
    }
    if (imax!=R)//Перевірка на те, чи є максимальний елемент на правильному місці
    {
        if (imax==L) //Якщо це не так - перевірка на те, чи стоїть максимальний елемент на місці мінімального
        {
            tmp=A[imin];//Якщо так - то перестановка його на найправіше місце
            A[imin]=A[R];
            A[R]=tmp;
        }
        else //Інакше - перестановка максимального елементу на найправіше місце
        {
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

clock_t Shell_1Vector(int *A, int N)//Функція, яка сортує вектор методом Шелла і повертає час який пішов на сортування
{
 int Elem, t, j, k;
 clock_t time_start, time_stop;
 time_start = clock();

 if (N<4) t=1;//Рахуємо потрібну величину кількості етапів
 else t=(int)log2f((float)N)-1;

 int Stages[t];
 Stages[t-1]=1;

 for (int i=t-2; i>=0; i--)//Заповнюємо масив розмірів відступу сусідніх елементів сортування
 Stages[i]=2*Stages[i+1]+1;

 for (int p=0; p<t; p++)//Цикл проходу всіх етапів
 {
    k=Stages[p];
    for (int i=k; i<N; i++)//Сортування елементів на відстані k одне від одного
    {
        Elem=A[i];
        j=i;
        while (j>=k && Elem<A[j-k])
        {
            A[j]=A[j-k];
            j=j-k;
        }
        A[j]=Elem;
    }
 }

 time_stop = clock();
 return time_stop - time_start;
}

clock_t Select1(int ***A, int N, int M, int P)//Функція, яка виконує сортування тривимірного масиву методом прямого вибору і повертає час сортування
{
 int Min, imin, Buffer;

 clock_t time_start, time_stop;
 time_start = clock();

 for(int PerCount=0;PerCount<P;PerCount++)
 {
     for(int s=0; s<N-1; s++)//Цикл, який йде по масиву, ставлячи мінімальні елементи в початок
    {
        Min=A[PerCount][0][s]; imin=s;
        for(int i=s+1; i<N; i++)//Внутрішній цикл, який знаходить мінімальне значення, якщо воно виявилося не на першому місці
        {
            if (A[PerCount][0][i]<Min)
            {
                Min=A[PerCount][0][i];
                imin=i;
            }
        }
        A[PerCount][0][imin]=A[PerCount][0][s];//Заміна послідоовних елементів масиву на мінімальне за останній прохід циклу
        A[PerCount][0][s]=Min;
        for(int RyadCount=1;RyadCount<M;RyadCount++)//А також переміщення елементів стовбцю відповідно до умови задачі
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


clock_t Select8(int ***A, int N, int M,int P)//Функція, яка виконує сортування тривимірного масиву методом вибору 8 і повертає час сортування
{
 int L, R, imin, imax, tmp;
 clock_t time_start, time_stop;
 time_start = clock();

 for(int PerCount=0;PerCount<P;PerCount++)//Цикл, який ходить по перерізам тривимірного масива
 {
 L=0; R=N-1;
 while (L<R)//Головний цикл, виконується поки границі L і R не перетнуться або не зрівняються
 {
    imin=L; imax=L;
    for(int i=L+1; i<R+1; i++)//Цикл, який одночасно шукає мінімум та максимум на проміжку від L+1 до R
    {
        if (A[PerCount][0][i]<A[PerCount][0][imin]) imin=i;
        else
            if (A[PerCount][0][i]>A[PerCount][0][imax]) imax=i;

    }
    if (imin!=L)//Перевірка на те, чи є мінімальний елемент на правильному місці
        {
            tmp=A[PerCount][0][imin];//Якщо це не так - відбувається перестановка мінімального
            A[PerCount][0][imin]=A[PerCount][0][L];//елементу на потрібне місце
            A[PerCount][0][L]=tmp;
            for(int RyadCount=1;RyadCount<M;RyadCount++)//А також переміщення елементів стовбцю відповідно до умови задачі
            {
                tmp=A[PerCount][RyadCount][imin];
                A[PerCount][RyadCount][imin]=A[PerCount][RyadCount][L];
                A[PerCount][RyadCount][L]=tmp;
            }
        }
    if (imax!=R)//Перевірка на те, чи є максимальний елемент на правильному місці
    {
      if (imax==L)//Якщо це не так - перевірка на те, чи стоїть максимальний елемент на місці мінімального
        {
            tmp=A[PerCount][0][imin];//Якщо так - то перестановка його на найправіше місце
            A[PerCount][0][imin]=A[PerCount][0][R];
            A[PerCount][0][R]=tmp;
            for(int RyadCount=1;RyadCount<M;RyadCount++)//А також переміщення елементів стовбцю відповідно до умови задачі
            {
                tmp=A[PerCount][RyadCount][imin];
                A[PerCount][RyadCount][imin]=A[PerCount][RyadCount][R];
                A[PerCount][RyadCount][R]=tmp;
            }
        }
        else//Інакше - перестановка максимального елементу на найправіше місце
        {
            tmp=A[PerCount][0][imax];
            A[PerCount][0][imax]=A[PerCount][0][R];
            A[PerCount][0][R]=tmp;
            for(int RyadCount=1;RyadCount<M;RyadCount++)//А також переміщення елементів стовбцю відповідно до умови задачі
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

clock_t Shell_1(int ***A, int N, int M, int P)//Функція, яка виконує сортування тривимірного масиву методом Шелла і повертає час сортування
{

 int Elem, t, j, k;
 int Buffer[M-1];
 clock_t time_start, time_stop;
 time_start = clock();

 for(int PerCount=0;PerCount<P;PerCount++)
 {
 if (N<4) t=1;//Рахуємо потрібну величину кількості етапів
 else t=(int)log2f((float)N)-1;
 int Stages[t];
 Stages[t-1]=1;

 for (int i=t-2; i>=0; i--)//Заповнюємо масив розмірів відступу сусідніх елементів сортування
 Stages[i]=2*Stages[i+1]+1;

 for (int p=0; p<t; p++)//Цикл проходу всіх етапів
 {
        k=Stages[p];
        for (int i=k; i<N; i++)//Сортування елементів на відстані k одне від одного
        {
                Elem=A[PerCount][0][i];
                for(int RyadCount=1;RyadCount<M;RyadCount++)
                {
                    Buffer[RyadCount-1]=A[PerCount][RyadCount][i];//Заповнення масиву буферу, оскільки тут треба
                }                                                 //запам'ятати елемент для його перестановки потім
                j=i;
                while (j>=k && Elem<A[PerCount][0][j-k])
                {
                        A[PerCount][0][j]=A[PerCount][0][j-k];
                        for(int RyadCount=1;RyadCount<M;RyadCount++)//А також переміщення елементів стовбцю відповідно до умови задачі
                        {
                            A[PerCount][RyadCount][j]=A[PerCount][RyadCount][j-k];
                        }
                        j=j-k;
                }
                A[PerCount][0][j]=Elem;
                for(int RyadCount=1;RyadCount<M;RyadCount++)//Перестановка рядку разом з елементом
                {
                    A[PerCount][RyadCount][j]=Buffer[RyadCount-1];
                }
        }
 }
 }
 time_stop = clock();
 return time_stop - time_start;
}
