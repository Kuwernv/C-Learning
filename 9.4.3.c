#include <stdio.h>
#include <stdlib.h>
char Menu(void);
int DatofYear(int year, int month, int day);
void MonthDay(int year, int yearDay, int *pMonth, int *pDay);
int days[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
                   {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
int main()
{
    int year, month, day, yearDay;
    switch (Menu())
    {
    case '1':
        printf("Please enter year,month,day:");
        scanf("%d,%d,%d", &year, &month, &day);
        yearDay = DatofYear(year, month, day);
        printf("yearDay = %d", yearDay);
        break;
    case '2':
        printf("Please input year,yearDay:");
        scanf("%d,%d", &year, &yearDay);
        MonthDay(year, yearDay, &month, &day);
        printf("%d/%d/%d", year, month, day);
        break;
    case '3':
        exit(0);
    default:
        printf("Input error!");
    }
}
char Menu(void)
{
    char mode;
    printf("1.year/ month/ day → yearDay\n2.yearDay → year/ month/ day\n3.Exit\n");
    printf("Choose:");
    while (scanf("%c", &mode) == 0)
    {
        printf("Choose:");
        fflush(stdin);
    }
    return mode;
}
int DatofYear(int year, int month, int day)
{
    int a = 0, yearDay = 0, i;
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        a = 1;
    for (i = 1; i < month; i++)
    {
        yearDay += days[a][i];
    }
    yearDay += day;
    return yearDay;
}
void MonthDay(int year, int yearDay, int *pMonth, int *pDay)
{
    int a = 0, i;
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        a = 1;
    for (i = 1; yearDay > days[a][i]; i++)
    {
        yearDay = yearDay - days[a][i];
    }
    *pMonth = i;
    *pDay = yearDay;
}