#include <stdio.h>
int main()
{
    int m,n;
    printf("   1   2   3   4   5   6   7   8   9\n   -   -   -   -   -   -   -   -   -\n");
    for(m=1;m<10;m++)
    {
        for(n=1;n<10;n++)
        {
            printf("%4d",m*n);
        }
        printf("\n");
    }
} 