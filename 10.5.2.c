#include <stdio.h>
#include <string.h>
#define N 100
void StrDel(char *pStr, char c);
int main()
{
    char str[N], ch;
    printf("Input a string:");
    gets(str);
    fflush(stdin);
    printf("Input a char:");
    ch = getchar();
    StrDel(str, ch);
    printf("%s", str);
}
void StrDel(char *pStr, char c)
{
    char str[N];
    char *t = str;
    strcpy(t, pStr);
    for (; *t != '\0'; t++)
    {
        if (*t != c)
        {
            *pStr = *t;
            pStr++;
        }
    }
    *pStr = '\0';
}