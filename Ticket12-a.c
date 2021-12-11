#include <stdio.h>
#include <stdlib.h>

#define n_max 10
#define m_max 10

#define vmin 10
#define vmax 20

int main()
{
	int n, m;
	printf("columns, rows: ");
	scanf("%d %d", &n, &m);

	int a[m_max][n_max];
	int b[m_max][n_max];

	int c1[m_max][n_max];
	int c2[m_max][n_max];

	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
		{
			a[i][j] = vmin + rand() % (vmax - vmin + 1);
			b[i][j] = vmin + rand() % (vmax - vmin + 1);
		}

	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
		{
			c1[i][j] = a[i][j] + b[i][j];
			c2[i][j] = a[i][j] - b[i][j];
		}

	char spc[100];
	for(int i = 0; i < 100; i++)
		spc[i] = ' ';
	spc[n * 4 / 2] = 0;

	printf("%sa%s\t%sb\n", spc, spc, spc);

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
			printf("% 4d", a[i][j]);

		printf("\t");

		for(int j = 0; j < n; j++)
		{
			printf("% 4d", b[i][j]);
		}
		printf("\n");
	}

	printf("\n%sc1%s\t%sc2\n", spc, spc, spc);

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
			printf("% 4d", c1[i][j]);

		printf("\t");

		for(int j = 0; j < n; j++)
		{
			printf("% 4d", c2[i][j]);
		}
		printf("\n");
	}

return 0;
}