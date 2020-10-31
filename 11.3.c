#include <stdio.h>
int main()
{
    int month;
    char *tab[] = {"January", "February", "March", "April",
                   "May", "June", "July", "August",
                   "September", "October", "November", "December"};
    printf("Input month:");
    while (scanf("%d", &month) == 0)
    {
        fflush(stdin);
        printf("Invalid Input!\n Please input month:");
    }
    if (month <= 12 && month >= 1)
        printf("month %d is %s \n", month, tab[month - 1]);
    else
        printf("Illegal month\n");
}