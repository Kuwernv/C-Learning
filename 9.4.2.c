#include <stdio.h>
void MonthDay(int year,int yearDay,int *pMonth,int *pDay);
int days[2][13] = {{0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {0,31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
int main()
{
    int year,yearDay,month,day;
    printf("Please input year,yearDay:");
    scanf("%d,%d",&year,&yearDay);
    MonthDay(year,yearDay,&month,&day);
    printf("%d/%d/%d",year,month,day);
    return 0;
}
void MonthDay(int year,int yearDay,int *pMonth,int *pDay)
{
    int a = 0,i;
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        a = 1;
    for(i = 1;yearDay>days[a][i];i++)
    {
        yearDay = yearDay - days[a][i];
    }
    *pMonth = i;
    *pDay = yearDay;
}