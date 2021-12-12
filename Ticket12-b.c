#include <stdio.h>
#include <stdlib.h>

#define n_max 10
#define m_max 10

#define vmin 10
#define vmax 20

int a[m_max][n_max];
int b[m_max][n_max];

int c1[m_max][n_max];
int c2[m_max][n_max];

int choice;
int columns, rows;

void input()
{
    printf("columns, rows: ");
    scanf("%d %d", &columns, &rows);

    for(int i = 0; i < rows; i++)
	    for(int j = 0; j < columns; j++)
		{
			a[i][j] = vmin + rand() % (vmax - vmin + 1);
			b[i][j] = vmin + rand() % (vmax - vmin + 1);
		}

}

void count()
{
    for(int i = 0; i < rows; i++)
    {
		for(int j = 0; j < columns; j++)
		{
			c1[i][j] = a[i][j] + b[i][j];
			c2[i][j] = a[i][j] - b[i][j];
		}
    }
}

void output()
{
    char spc[100];
	for(int i = 0; i < 100; i++)
		spc[i] = ' ';
	spc[columns * 4 / 2] = 0;

	printf("%sa%s\t%sb\n", spc, spc, spc);

	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
			printf("% 4d", a[i][j]);

		printf("\t");

		for(int j = 0; j < columns; j++)
		{
			printf("% 4d", b[i][j]);
		}
		printf("\n");
	}

	printf("\n%sc1%s\t%sc2\n", spc, spc, spc);

	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
			printf("% 4d", c1[i][j]);

		printf("\t");

		for(int j = 0; j < columns; j++)
		{
			printf("% 4d", c2[i][j]);
		}
		printf("\n");
	}
}

int  main()
{
    do
    {
        printf("0 - extit\n");
        printf("1 - input\n");
        printf("2 - count\n");
        printf("3 - output\n");
        printf("choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
            case 1: input(); 
            break;
            case 2: count();
            break;
            case 3: output();
            break;
        }
    }    
    while (choice != 0);
    return 0;
}