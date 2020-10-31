#include <stdio.h>
#include <string.h>
#define N 100
void InverseStr(char *str);
/*void InverseStr(char str[]);*/
int main()
{
    char str[N];
    printf("Input a string:");
    gets(str);
    InverseStr(str);
    printf("%s", str);
}
/*void InverseStr(char str[])
{
    int i,j;
    char temp[N];
    strcpy(temp,str);
    for(i=strlen(str)-1,j=0;i>=0;i--,j++)
    {
        str[j] = temp[i];
    }
    str[i] = '\0';
}*/
void InverseStr(char *str)
{
    int length;
    char temp;
    char *pStart;
    char *pEnd;
    length = strlen(str);
    for (pStart = str, pEnd = str + length - 1; pStart < pEnd; pStart++, pEnd--)
    {
        temp = *pStart;
        *pStart = *pEnd;
        *pEnd = temp;
    }
}