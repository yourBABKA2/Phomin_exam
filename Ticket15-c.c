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
    FILE *f = fopen("Ticket15.txt", "w+");
    fprintf(f, "os    virt    phy    price\n");

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
        fprintf(f, "%s\t%d\t%d\t%d\n", tab[i].os, tab[i].virt, tab[i].phy, tab[i].price);
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
            fprintf(f, "virt: %s\n", tab[i].virt);
            printf("phy: %s\n", tab[i].phy);
            fprintf(f, "%s\n", tab[i].phy);
            printf("price: %d\n", tab[i].price);
            fprintf(f, "price: %d\n", tab[i].price);
            n++;
        }
    }
    if(n < 1)
    { 
        printf("not found!\n");
        fprintf(f, "not found!\n");
    }

    for (int i = rows - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (tab[j].price > tab[j + 1].price)
            {
                int tmp = tab[j].price;
                tab[j].price = tab[j + 1].price;
                tab[j + 1].price = tmp;
            }
        }
        min =  tab[i].price;

        for(int i = 0; i < rows; i++)
        {
	        if(tab[i].price < min) min = tab[i].price;
        }   
    }
    printf("min = %d\n", min);
    fprintf(f, "min = %d\n", min);

return 0;
}