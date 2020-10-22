#include <stdio.h>
int DatofYear(int year, int month, int day);
int days[2][13] = {{0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {0,31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
int main()
{
    int year, month, day, yearDay;
    printf("Please enter year,month,day:");
    scanf("%d,%d,%d", &year, &month, &day);
    yearDay = DatofYear(year, month, day);
    printf("yearDay = %d", yearDay);
    return 0;
}
int DatofYear(int year, int month, int day)
{
    int a = 0,yearDay = 0,i;
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        a = 1;
    for(i=1;i<month;i++)
    {
        yearDay += days[a][i];
    }
    yearDay += day;
    return yearDay;
}