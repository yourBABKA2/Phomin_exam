#include <stdio.h>
#include <string.h>

struct record
{
	char Surname[32];
	char Category[32];
	char Phone_Number[24];
	char Information[64];
};

#define rows 3
struct record tab[rows];

int main()
{
    for(int i = 0; i < rows; i++)
    {
        int n = i + 1;
	    printf("[record %d]\n", n);

    	printf("Surname: ");
	    gets(tab[i].Surname);

    	printf("Category: ");
    	gets(tab[i].Category);

    	printf("Phone Number: ");
    	gets(tab[i].Phone_Number);

    	printf("Information: ");
    	gets(tab[i].Information);

    	printf("\n");
	}

    for(int i = 0; i < rows; i++)
    {
		printf("%s\t%s\t%s\t%s\n", tab[i].Surname, tab[i].Category, tab[i].Phone_Number, tab[i].Information);
    }

    printf("search: ");
    char Surname[32];
    gets(Surname);
        
    char Category[32];
    char Phone_Number[24];
    char Information[64];

    for (int i = 0; i < 32; i++)
        Category[i] = Surname[i];

    printf("\n");

    int n = 0;

    for(int i = 0; i < rows; i++)
    {
        n++;
        char *s = strtok(tab[i].Surname, " ");
        if (strcmp(s, Surname) == 0)
        {
            printf("Surname: %s\n", tab[i].Surname);
            printf("Category: %s\n", tab[i].Category);
            printf("Phone Number: %s\n", tab[i].Phone_Number);
            printf("Information: %s\n", tab[i].Information);
        }
	}
    if(n < 1) printf("not found!\n");
    return 0;
}