#include <stdio.h>
#include <string.h>
void FindDay(char *c);
int main()
{
    char c[10];
    printf("Input Weekday:");
    scanf("%s",c);
    FindDay(c);
}
void FindDay(char *c)
{
    int i;
    char tab[][10] ={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    for(i=0;i<=6;i++)
    {
        if (strcmp(c,tab[i])==0)
        {
            printf("%d\n",i);
            return;
        }
    }
    printf("Not found!\n");
}