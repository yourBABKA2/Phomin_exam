#include <stdio.h>
#include <stdlib.h>

#define n_max 10
#define m_max 10

#define vmin 10
#define vmax 20

int **a, **b, **c1, **c2;

int choice;
int columns, rows;

void show(int **e)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            printf("%d\t", e[i][j]);
        printf("\n");
    }
}

void input_first()
{
    for (int i = 0; i < rows; i++)
    {
        a[i] = (int *)malloc(rows * sizeof(int));
        for (int j = 0; j < columns; j++)
            a[i][j] = vmin + rand() % (vmax - vmin + 1);
    }
    printf("\nfirst: \n");
    show(a); 
}

void input_second()
{
    for (int i = 0; i < rows; i++)
    {
        b[i] = (int *)malloc(rows * sizeof(int));
        for (int j = 0; j < columns; j++)
            b[i][j] = vmin + rand() % (vmax - vmin + 1);
    }
    printf("\nsecond: \n");
    show(b); 
}

void add()
{
    for (int i = 0; i < rows; i++)
    {
        c1[i] = (int *)malloc(rows * sizeof(int));
        for (int j = 0; j < columns; j++)
            c1[i][j] = a[i][j] + b[i][j];
    }
    printf("\nadd: \n");
    show(c1);
}

void sub()
{
    for (int i = 0; i < rows; i++)
    {
        c2[i] = (int *)malloc(rows * sizeof(int));
        for (int j = 0; j < columns; j++)
            c2[i][j] = a[i][j] - b[i][j];
    }
    printf("\nsub: \n");
    show(c2);
}

int  main()
{
    do
    {
        printf("columns, rows: ");
        scanf("%d %d", &columns, &rows);
    } 
    while (columns < 1 || rows > 10);
    a = (int **)malloc(columns *sizeof(int *));
    b = (int **)malloc(columns *sizeof(int *));
    c1 = (int **)malloc(columns *sizeof(int *));
    c2 = (int **)malloc(columns *sizeof(int *));

    do
    {
        printf("0 - extit\n");
        printf("1 - first array\n");
        printf("2 - second array\n");
        printf("3 - add\n");
        printf("4 - substract\n");
        printf("choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: input_first(); 
            break;
            case 2: input_second();
            break;
            case 3: add();
            break;
            case 4: sub();
            break;
        }
    }    
    while (choice != 0);
    for (int i = 0; i < columns; i++)
    {
        free(a[i]);
        free(b[i]);
        free(c1[i]);
        free(c2[i]);
    }

    free(a);
    free(b);
    free(c1);
    free(c2);
    return 0;
}