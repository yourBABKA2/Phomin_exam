/*
    Имеются данные сбера о стоимости доллара к рублю в течении месяца массив заполняется случайными данными в диапазоне от 10 до 50
    3 указать самый высоки и самый низкий курс доллара
    4 чтение исходных данных в массив выполнять из подготовленного заранее текстового файла 
    5 осуществить поиск нужного курса, и указать в какой день он был установлен
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    /*
    float a = 0.84f;
    float b = rand() / (float) RAND_MAX;

    printf("%.2f %.2f\n", a, b);

#define epsilon 0.001f
    float b0 = b - epsilon;
    float b1 = b + epsilon;
    if (fabs(b - a) < epsilon) puts("EQUALS");
*/

    #define days 31
    #define coeff_lo 10.001f
    #define coeff_hi 50.0f
    float coeff[days];

    FILE *f;
    f = fopen("Ticket9.txt","w");

    for (int i = 0; i < days; i++)
    {
        coeff[i] = coeff_lo + (coeff_hi - coeff_lo) * rand() / RAND_MAX;
        fprintf(f, "%.2f\n", coeff[i]);
    }

    if (days % 7 > 0)
        fprintf(f, "\n");
    fclose(f);

    f = fopen("Ticket9.txt","r");
    for (int i = 0; i < days; i++)
    {
        fscanf(f, "%.2f", &coeff[i]);
        printf("% 6.2f", coeff[i]);
        if (i % 7 == 6)
            printf("\n");
    }

    if (days % 7 > 0)
        printf("\n");

    float cmin = coeff_hi;
    float cmax = coeff_lo;

    for (int i = 0; i < days; i++)
    {
        if (coeff[i] < cmin) 
            cmin = coeff[i];
        if (coeff[i] > cmax)
            cmax = coeff[i];
    }

    printf("\n");
    printf("min = %.2f\n", cmin);
    printf("max = %.2f\n", cmax);

    return 0;
}