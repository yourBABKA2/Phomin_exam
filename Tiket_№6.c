#include <stdio.h>
#include <stdlib.h> //для rand
#define days 31
int pres[days];

#define p_min 740
#define p_max 780
#define p_norm 760

int main()
{
    for (int i = 0,; i < days; i++)
    {
        pressure[i] = p_min + rand() % (p_max - p_min +1);
    }


    printf("day\tpressure\n")
    for (int i = 0; i < days; i++)
    {
        print("%d\t%d", i, + 1, pressurep[i]);
    }

    int cnt_below = 0;
    int cnt_above = 0;
    int cnt_exact = 0;
    for (int i = 0; i < days; i++)
    {
        int v = pressure[i];
        if (v < p_norm)
        cnt_above++;
        else if (v > p_norm)
        cnt_above++;
        else cnt_exact++;
    }

    printf("delow:");
    printf("");
    printf("");
    return 0;
}
//git -add
//git -m "надпись"
//git push


/*
740
750
760
770
*/