#include <stdio.h>
#include <stdlib.h>

#define mark0 1
#define mark1 10
#define cols 5

int main()
{
    int rows;
    printf("rows: ");
	scanf("%d", &rows ); 

	int tab[rows][cols];

	for(int i = 0; i < rows; i++)
		for(int j = 0; j < cols; j++)
			tab[i][j] = mark0 + rand() % (mark1 - mark0 + 1);

	float avg[rows];	
	for(int i = 0; i < rows; i++)
	{
		int s = 0;
		for(int j = 0; j < cols; j++)
			s += tab[i][j];
		avg[i] = s / (float)cols;
	}

    int notbs = 0 ;
    float best = avg[0];

    for(int i = 1; i < rows; i++ )
    {
        if (best < avg[i])
        {
            best = avg[i];
            notbs = i + 1;
        }
    }
	printf("num");
	for(int i = 0; i < cols; i++)
		printf("\t%d", i + 1);
	printf("\tavg\n");

	for(int i = 0; i < rows; i++)
	{
		printf("%d", i + 1);
		for(int j = 0; j < cols; j++)
			printf("\t%d", tab[i][j]);
		printf("\t%.1f\n", avg[i]);
	}
    printf("Num of the best sportsman: %d\n", notbs);
    return 0;
}