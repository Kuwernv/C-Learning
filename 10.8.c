#include <stdio.h>
#include <string.h>
#define N 100
void MyStrcat(char dstStr[],char srcStr[]);
int main()
{
    char s[N],t[N];
    printf("Input a string:");
    gets(s);
    printf("Input another string:");
    gets(t);
    MyStrcat(s,t);
    printf("%s",s);
    return 0;
}
void MyStrcat(char dstStr[],char srcStr[])
{
    int i,j;
    i = strlen(dstStr);
    for(j=0;j<=strlen(srcStr);j++,i++)
    {
        dstStr[i] = srcStr[j];
    }
}