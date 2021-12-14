/*
    3 имеется текствый файл, оформленный в виде теста, каждый вопрос теста имеет следующую структуру:
    сам вопрос, 4 варианта ответа и правильный вариант ответа,
    провести тест используя данный файл
    4 ввести сохранения в текстовом файле всех результатов тестирования в виде:
    ФИО, номер группы и конечный результат тестирования
*/

#include <stdio.h>

#define max_ans 5
#define max_txt 100
char name[32];
char lastname[32];
char group[32];
int answer[32];

struct quest
{
    int nans;
    int corr;
    char txt[max_txt];
    char ans[max_ans][max_txt];
};

#define max_quest 10
struct quest test[max_quest];

int main()
{
    FILE *f = fopen("Ticket19.txt", "r");
    int nq;

    printf("Enter your Name, Last Name and number of your group!\n");    
    fscanf(f, "%d", &nq);

    for (int i = 0; i < nq; i++)
    {
        fscanf(f, "%d %d\n", &test[i].nans, &test[i].corr);
        fgets(test[i].txt, max_txt, f);
        for (int j = 0; j < test[i].nans; j++)
            fgets(test[i].ans[j], max_txt, f);
    }
    fclose(f);

    FILE *fp = fopen("StudInfo.txt", "w+");
    fgets(name, 32, stdin);
    fgets(lastname, 32, stdin);
    fgets(group, 32, stdin);

    fprintf(fp, "%s", name);
    fprintf(fp, "%s", lastname);
    fprintf(fp, "%s", group);
    fprintf(fp, "--------------------\n");

    for (int i = 0; i < nq; i++)
    {
        printf(test[i].txt);
        fprintf(fp, "%s", test[i].txt);
        for (int j = 0; j < test[i].nans; j++)
        {
            printf(test[i].ans[j]);
        }
        int c;
        scanf("%d", &c);

        if (c == test[i].corr)
        {
            puts("correct!");
            fprintf(fp, "Correct!\n");
        }
        else
        { 
            puts("wrong!");
            fprintf(fp, "wrong!\n");
        }    
    }


    fclose(fp);
return 0;
}