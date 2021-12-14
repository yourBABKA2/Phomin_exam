#include <stdio.h>
#include <string.h> // strlen()

int main()
{
    char string[30];	
    fgets(string, 30, stdin);	

    char *m = strchr(string, '\n');
    if(m != NULL)
    {
        *m = '\0';
    } 
    char s1[30];
    int number[30];
    for (int i = 0;i < 30;i++)
        number[i] = 0;
    int j = 1;
    s1[0] = string[0];
    number[0] = 1;
    int k = 0;
    while (string[j] != '\0')
    {
        if (string[j] == string[j - 1])
        {
            number[k]++;
        }
        else 
        {
            k++;
            s1[k] = string[j];
            number[k]++;
        }
        j++;
    }
    s1[k + 1] = '\n';
    number[k + 1] = 0;
    char *z = strchr(s1, '\n');
    if(z != NULL) *z = '\0';
    int g = strlen(s1);    

    for(int i = 0;i < g; i++)
    {
        if ((number[i]  !=  1)  &&  (number[i]   !=  0)  &&  (s1[i]  !=  '\0'))
        printf("%c%d", s1[i], number[i]);
        else
        printf("%c",s1[i]);
    }
    printf("\n");
    for(int i = 0; i < g;i++)
        for(int j = 0; j < number[i]; j++)
            printf("%c",s1[i]);
    printf("\n");

return 0;
}