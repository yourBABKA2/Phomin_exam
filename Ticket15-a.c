#include <stdio.h>
#include <string.h>

struct record
{
    char os[32];
    char virt[32];
    char phy[32];
    int price;
};

#define rows 3
struct record tab[rows];

int min;

int  main()
{
    char tmp[32];

    for(int i = 0; i < rows; i++)
    {
        printf("[record %d]\nos, virt, phy, price: ", i);
        scanf("%s %s %s %d", tab[i].os, &tab[i].virt, &tab[i].phy, &tab[i].price);
        printf("\n");
    }

    for(int i = 0; i < rows; i++)
    {
        printf("%s\t%s\t%s\t%d\n", tab[i].os, tab[i].virt, tab[i].phy, tab[i].price);
    }

    char os[32];
    printf("search: ");
    scanf("%s", os);
    printf("\n");

    int n = 0;

    for(int i = 0; i < rows; i++)
    {
        if(strcmp(tab[i].os, os) == 0)
        {
            printf("virt: %s\n", tab[i].virt);
            printf("phy: %s\n", tab[i].phy);
            printf("price: %d\n", tab[i].price);
            n++;
        }
    }
    if(n < 1) printf("not found!\n");
return 0;
}