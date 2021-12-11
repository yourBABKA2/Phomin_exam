#include <stdio.h>
#include <stdlib.h>

#define rows 25
#define cols 5

#define mark0 2
#define mark1 5

int main()
{
	int tab[rows][cols];

	for(int i = 0; i < rows; i++)
		for(int j = 0; j < cols; j++)
			tab[i][j] = mark0 + rand() % (mark1 - mark0 + 1);

	float avg[rows];	
	for(int i = 0; i < rows; i++)
	{
		int s = 0;
		for(int j = 0; j < cols; j++)
		{
			s += tab[i][j];
		}
		avg[i] = s / (float)cols;
	}

	printf("num");
	for(int i = 0; i < cols; i++)
	{
		printf("\t%d", i + 1);
	}

	printf("\tavg\n");

	for(int i = 0; i < rows; i++)
	{
		printf("%d", i + 1);
		for(int j = 0; j < cols; j++)
		{
			printf("\t%d", tab[i][j]);
		}
		printf("\t%.1f\n", avg[i]);
	}

	return 0;
}