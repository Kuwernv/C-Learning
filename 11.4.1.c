#include <stdio.h>
#define N 10
void SwapInt(int *x,int *y);
void Transpose(int *a,int n);
void InputMartix(int *a,int n);
void PrintMartix(int *a,int n);
int main()
{
    int a[N][N], n;
    printf("Input n:");
    scanf("%d",&n);
    InputMartix(*a,n);
    Transpose(*a,n);
    PrintMartix(*a,n);
    return 0;
}
void SwapInt(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void Transpose(int *a,int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            SwapInt(&a[i*n+j],&a[j*n+i]);
        }
    }
}
void InputMartix(int *a,int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i*n+j]);
        }
    }
}
void PrintMartix(int *a,int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",a[i*n+j]);
        }
        printf("\n\n\n\n");
    }
}