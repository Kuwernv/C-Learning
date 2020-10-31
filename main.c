/**************************
** 程序描述:学生成绩管理系统 
** 日 期:2020/10/30
** 作业题目:学生成绩管理系统
** 输入:学生人数（小于等于30人）、每个学生的学号与成绩
** 输入范围：人数小于等于30人，成绩应在0-100之间，学号小于等于2147483647
** 输出： 根据用户选择的功能输出不同，有总分和平均分、学生的学号与成绩、每个类别的人数和百分比
***************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STU_NUM 30 //最大学生人数
#define MAX_LEN 10
int Menu();
void ReadScore(char name[][MAX_LEN], int ID[], float score[], int n);
void AvgSumofScore(float score[], int n);
void SortbyScore(char name[][MAX_LEN], int ID[], float score[], int n, int (*compare)(float a, float b));
int Asscending(float a, float b);
int Descending(float a, float b);
void SwapFloat(float *x, float *y);
void SwapInt(int *x, int *y);
void SwapChar(char *x, char *y);
void SortbyName(char name[][MAX_LEN], int ID[], float score[], int n);
void AsSortID(char name[][MAX_LEN], int ID[], float score[], int n);
void LineSearchID(char name[][MAX_LEN],int ID[], float score[], int n);
void LineSearchName(char name[][MAX_LEN],int ID[], float score[], int n);
void StatisticAnalysis(float score[], int n);
void PrintScore(char name[][MAX_LEN], int ID[], float score[], int n);
int main()
{
    int n = 0;
    char name[STU_NUM][MAX_LEN];
    int ID[STU_NUM][2];      //学生ID数组
    float score[STU_NUM][3]; //学生成绩数组
    while (1)
    {
        switch (Menu())
        {
        case 1:
            printf("Input stndent number(n<%d):", STU_NUM);
            while (scanf("%d", &n) != 1 || n > 30 || n < 0) //确保输入一个小于30整数
            {
                fflush(stdin);
                printf("Invalid input!\nInput stndent number(n<%d):", STU_NUM);
            }
            ReadScore(name, ID, score, n); //录入分数
            printf("Input Finished\n\n");  //提示录入结束
            break;
        case 2:
            AvgSumofScore(score, n); //计算总分平均分
            break;
        case 3:
            SortbyScore(name, ID, score, n, Descending); //按照成绩降序排列
            PrintScore(name, ID, score, n);              //输出学生姓名、学号与成绩
            break;
        case 4:
            SortbyScore(name, ID, score, n, Asscending); //按照成绩升序排列
            PrintScore(name, ID, score, n);              //输出学生姓名、学号与成绩
            break;
        case 5:
            AsSortID(name, ID, score, n);   //按照学号升序排列
            PrintScore(name, ID, score, n); //输出学生姓名、学号与成绩
            break;
        case 6:
            SortbyName(name, ID, score, n);   
            PrintScore(name, ID, score, n); 
            break;
        case 7:
            LineSearchID(name,ID, score, n); //搜索学生ID并返回其成绩
            break;
        case 8:
            LineSearchName(name,ID, score, n); //搜索学生姓名并返回其成绩
            break;
        case 9:
            StatisticAnalysis(score, n); //计算输出每个类别的人数和百分比
            break;
        case 10:
            PrintScore(name, ID, score, n); //输出学生姓名、学号与成绩
            AvgSumofScore(score, n);        //计算总分平均分
            break;
        case 11:
            exit(0);
            break;
        default:
            printf("Invalid Input\n"); //输入错误
            break;
        }
    }
}
/* 函数功能：显示菜单，返回用户选择的选项 */
int Menu()
{
    int choice;
    printf("1. Input record\n"
           "2. Calculate total and average score of course\n"
           "3. Sort in descending order by score\n"
           "4. Sort in ascending order by score\n"
           "5. Sort in ascending order by number\n"
           "6. Sort in dictionary order by name\n"
           "7. Search by number\n"
           "8. Search by name\n"
           "9. Statistic analysis!\n"
           "10.List record\n"
           "11.Exit\n"
           "Please enter your choice:");
    while (scanf("%d", &choice) != 1) //确保输入一个整数
    {
        fflush(stdin);
        printf("Invalid input!\nPlease enter your choice:");
    }
    return choice;
}
/* 函数功能：录入学生学号与对应的成绩 */
void ReadScore(char name[][MAX_LEN], int ID[], float score[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Input No.%d stndent's ID,Name and score:\n", i + 1);
        scanf("%d%s%f",&ID[i], name[i], &score[i]);
    }
}
/* 函数功能：计算总分和平均分 */
void AvgSumofScore(float score[], int n)
{
    int i;
    float sum = 0;
    for (i = 0; i < n; i++)
    {
        sum = sum + score[i];
    }
    printf("Total Score = %.0f,Average Score = %.2f\n\n", sum, n > 0 ? sum / n : 0);
}
/* 函数功能：按照成绩排序，通过函数指针控制升序or降序 */
void SortbyScore(char name[][MAX_LEN], int ID[], float score[], int n, int (*compare)(float a, float b))
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if ((*compare)(score[j], score[k]))
                k = j;
        }
        if (k != i)
        {
            SwapFloat(&score[k], &score[i]);
            SwapInt(&ID[k], &ID[i]);
            SwapChar(name[k],name[i]);
        }
    }
}
/* 函数功能：函数指针（升序） */
int Asscending(float a, float b)
{
    return a < b;
}
/* 函数功能：函数指针（降序） */
int Descending(float a, float b)
{
    return a > b;
}
/* 函数功能：交换两个浮点数数据 */
void SwapFloat(float *x, float *y)
{
    float temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
/* 函数功能：交换两个整数数据 */
void SwapInt(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
/* 函数功能：交换两个字符串 */
void SwapChar(char *x, char *y)
{
    char temp[MAX_LEN];
    strcpy(temp,x);
    strcpy(x,y);
    strcpy(y,temp);
}
/* 函数功能：按姓名排序 */
void SortbyName(char name[][MAX_LEN], int ID[], float score[], int n)
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(name[k],name[j])>0)
                k = j;
        }
        if (k != i)
        {
            SwapFloat(&score[k], &score[i]);
            SwapInt(&ID[k], &ID[i]);\
            SwapChar(name[k],name[i]);
        }
    }
}
/* 函数功能：按照学号升序排列 */
void AsSortID(char name[][MAX_LEN], int ID[], float score[], int n)
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if (ID[j] < ID[k])
                k = j;
        }
        if (k != i)
        {
            SwapFloat(&score[k], &score[i]);
            SwapInt(&ID[k], &ID[i]);\
            SwapChar(name[k],name[i]);
        }
    }
}
/* 函数功能：根据学号搜索成绩并输出 */
void LineSearchID(char name[][MAX_LEN],int ID[], float score[], int n)
{
    int i;
    int targetID;
    printf("Input ID:");
    while (scanf("%ld", &targetID) != 1)
    {
        fflush(stdin);
        printf("Invalid input!\nPlease Input ID:");
    }
    for (i = 0; i < n; i++)
    {
        if (ID[i] == targetID)
        {
            printf("%ld\t%s\t%.0f\n\n", ID[i],name[i], score[i]);
            return;
        }
    }
    printf("Not found!\n");
}
/* 函数功能：根据姓名搜索成绩并输出 */
void LineSearchName(char name[][MAX_LEN],int ID[], float score[], int n)
{
    int i;
    char target[MAX_LEN];
    printf("Input nmae:");
    while (scanf("%s", &target) != 1)
    {
        fflush(stdin);
        printf("Invalid input!\nPlease Input ID:");
    }
    for (i = 0; i < n; i++)
    {
        if (strcmp(target,name[i])==0)
        {
            printf("%ld\t%s\t%.0f\n\n", ID[i],name[i], score[i]);
            return;
        }
    }
    printf("Not found!\n");
}
/* 函数功能：成绩分析，统计各分数段人数与百分比 */
void StatisticAnalysis(float score[], int n)
{
    int i, t[5] = {0, 0, 0, 0, 0};
    for (i = 0; i < n; i++)
    {
        if (score[i] >= 90 && score[i] <= 100)
            t[0]++;
        if (score[i] >= 80 && score[i] <= 89)
            t[1]++;
        if (score[i] >= 70 && score[i] <= 79)
            t[2]++;
        if (score[i] >= 60 && score[i] <= 69)
            t[3]++;
        if (score[i] >= 0 && score[i] <= 59)
            t[4]++;
    }
    printf("90-100 %d\t%.2f%%\n", t[0], (float)t[0] / n * 100);
    printf("80-89  %d\t%.2f%%\n", t[1], (float)t[1] / n * 100);
    printf("70-79  %d\t%.2f%%\n", t[2], (float)t[2] / n * 100);
    printf("60-69  %d\t%.2f%%\n", t[3], (float)t[3] / n * 100);
    printf("0-59   %d\t%.2f%%\n", t[4], (float)t[4] / n * 100);
}
/* 函数功能：打印学生学号与成绩 */
void PrintScore(char name[][MAX_LEN], int ID[], float score[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%ld\t%s\t%.0f\n", ID[i],name[i], score[i]);
    }
}
