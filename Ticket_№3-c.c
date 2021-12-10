/*
    задаётся точка где находится пушка, даются координаты выстрела,
    угол под которым вылетает снаряд и его сокрость.
    найти где приземлится снаряд, время полёта и расчитать координаты падения?
    3 - просто расчёт
    4 - вывод во время цикла
    5 - с помошью бисекций
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float x0, y0;
    printf("x0, y0: ");
    scanf("%f %f", &x0, &y0);

    float v0, alpha;
    printf("v0, a: ");
    scanf("%f %f", &v0, &alpha);

    float ra = alpha * (float) M_PI / 180.0f;

    float v0x = cosf(ra) * v0;
    float v0y = sinf(ra) * v0;

    #define g 9.8f
    float d = v0y * v0y + 4.0f * (g / 2.0f) * y0;
    printf("d = %f\n", d);

    float t = 0.0f;
    float x, y3,y1,y2;

#define eps 0.00000000000001f
    float t1 = v0y/g;
    float t3=0;
    float t2 = t1;
    while(1) 
    {
        t2 = t2 + 10.0f;
        y2 = y0 + v0y * t2 - g * t2 * t2 / 2.0f;
        if (y2 < 0) break;
    }
    while(1)
    {
        t3=(t1+t2)/2;
        x = x0 + v0x * t3;
        y3 = y0 + v0y * t3 - g * t3 * t3 / 2.0f;
        y1 = y0 + v0y * t1 - g * t1 * t1 / 2.0f;
        y2 = y0 + v0y * t2 - g * t2 * t2 / 2.0f;

        if (y1*y3<0)
            {t2=t3;}
        else t1=t3;
            float G = fabs(t2-t1);
        if(fabs(t2-t1)<=eps)
            break;

        printf("%f %f %f\n", t3, x, y3);


    }
    
    t=t3;
    printf("t = %f, x = %f, y = %f\n", t, x, y3);

    return 0;
}