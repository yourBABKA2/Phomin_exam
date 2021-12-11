#include <stdio.h>
#include <stdlib.h>

#define rows 25
#define cols 5

#define mark0 2
#define mark1 5

int main()
{
    int table[rows][cols];

	for(int i = 0; i < rows; i++)
		for(int j = 0; j < cols; j++)
			table[i][j] = mark0 + rand() % (mark1 - mark0 + 1);

	float avg[rows];
	float avg4[cols];	
	for(int i = 0; i < rows; i++)
	{
		int s = 0;
		for(int j = 0; j < cols; j++)
		{
			s += table[i][j];
		}
		avg[i] = s / (float) cols;
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
			printf("\t%d", table[i][j]);
		}
		printf("\t%.1f\n", avg[i]);
	}

	float marks = 6;
	int bad = 0;

	for(int i = 0; i < cols; i++)
	{
		int s = 0;
		for(int j = 0; j < rows; j++)
		{
			s += table[j][i];
		}

		avg4[i] = s / (float) rows;

		if(avg4[i] < marks)
		{
			marks = avg4[i];
			bad = i + 1;
		}
	}
 	printf("The worst subject %d\n", bad);
	return 0;
}