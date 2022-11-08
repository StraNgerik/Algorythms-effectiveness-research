#include "Measurement.h"
#include <stdio.h>

// Масив значень часу роботи алгоритма
    clock_t Res[measurements_number];
    float MeasurementProcessing()//Функція, яка виконує усереднення значень
    {
        long int Sum;//Сума
        float AverageValue;//Усереднене значення часу роботи алгоритма

        clock_t buf;
        int L = rejected_number, R = measurements_number - 1;
        int k = rejected_number;
        for (int j=0; j < min_max_number; j++)
        {
            for (int i = L; i < R; i++)
            {
                if (Res[i] > Res[i + 1])
                {
                buf = Res[i];
                Res[i] = Res[i + 1];
                Res[i + 1] = buf;
                k = i;
                }
            }
            R = k;
            for (int i = R - 1; i >= L; i--)
            {
                if (Res[i] > Res[i + 1])
                {
                    buf = Res[i];
                    Res[i] = Res[i + 1];
                    Res[i + 1] = buf;
                    k = i;
                }
            }
            L = k + 1;
        }

        Sum=0;
        for (int i = rejected_number + min_max_number; i < measurements_number - min_max_number; i++) Sum = Sum + Res[i];

        AverageValue = (float)Sum / (float)(measurements_number - 2*min_max_number - rejected_number);

        return AverageValue;
}
