#include <stdio.h>
#define N 100
void StrDel(char s[], char c);
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
void StrDel(char s[], char c)
{
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
    {
        if (s[i] != c)
        {
            s[j] = s[i];
            j++;
        }
    }
    s[j] = '\0';
}