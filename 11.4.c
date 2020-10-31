#include <stdio.h>
#define N 10
void SwapInt(int *x,int *y);
//void Transpose(int a[][N],int n);//
//void Transpose(int (*a)[N],int n);//
void InputMartix(int a[][N],int n);
void PrintMartix(int a[][N],int n);
int main()
{
    int a[N][N], n;
    printf("Input n:");
    scanf("%d",&n);
    InputMartix(a,n);
    Transpose(a,n);
    PrintMartix(a,n);
    return 0;
}
void SwapInt(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
/*void Transpose(int a[][N],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            SwapInt(&a[i][j],&a[j][i]);
        }
    }
}*/
/*void Transpose(int (*a)[N],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            SwapInt(*(a+i)+j,*(a+j)+i);
        }
    }
}*/
void InputMartix(int a[][N],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}
void PrintMartix(int a[][N],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n\n\n\n");
    }
}