#include <stdio.h>
int main()
{
    int a[] ={1,2,3,4,5};
    int *p = a;
    printf("%d,",*(++p));//先+1,再取值输出
    printf("%d,",(*p)++);//先取值,p再+1
    printf("%d,",*p);
    printf("%d,",*p);
    printf("%d,",*p--);//先取值输出,p再-1
    printf("%d,",--(*p));//先p-1,再输出
    printf("%d,",*p);
}