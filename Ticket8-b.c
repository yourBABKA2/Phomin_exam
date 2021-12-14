#include <stdio.h>
#include <stdlib.h>

#define month 12
#define salary_min 1000
#define salary_max 5000

int main()
{
    int salary[month];
    float tax[month];
    for (int i = 0; i < month; i++)
        salary[i] = salary_min + rand() % (salary_max - salary_min + 1);

    for (int i = 0; i < month; i++)
    {
        printf("%6d", (i + 1));
    }
    printf("\n");

    for (int i = 0; i < month; i++)
    {
        printf("%6d", salary[i]);
    }
    printf("\n");

    float year_tax = 0.0f;
    for (int i = 0; i < month; i++)
    {
        float tax_ = salary[i] * 0.02f;
        year_tax += tax_;
        printf("% 6.1f", tax_);
    }
    printf("\n");

//sum
    int year_sum = 0;
    for (int i = 0; i < month; i++)
    {
        year_sum += salary[i];
    }
    
//avg
    float year_avg = 0.0f;
    year_avg = (float) year_sum / (float) month;

    float year_avg_tax = year_tax / month;
    for (int i = 0; i < month; i++)
    {
        tax[i] = salary[i] * 0.02f;
        float e = tax[i] - year_avg_tax;
        printf("% 6.1f", e);
        year_tax += tax[i];
    }

    printf("\n");

    printf("year_sum = %d\n", year_sum);
    printf("year_avg = %0.2f\n", year_avg);
    printf("year_tax = %0.2f\n", year_tax);
    printf("year_avg_tax = %0.2f\n", year_avg_tax);
    return 0;
}
