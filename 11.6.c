#include <stdio.h>
#include <stdlib.h>
void InputArray(int *p, int n);
double Average(int *p, int n);
int main()
{
    int *p = NULL, n;
    double aver;
    printf("How many students?");
    scanf("%d", &n);
    p = (int *)malloc(n * sizeof(int));
    if (p == NULL)
    {
        printf("No enough memory! \n");
        exit(1);
    }
    printf("Input %d score:", n);
    InputArray(p, n);
    aver = Average(p, n);
    printf("aver = %.1f\n", aver);
    free(p);
    return 0;
}
void InputArray(int *p, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
}
double Average(int *p, int n)
{
    int i, sum = 0;
    for (i = 0; i < n; i++)
    {
        sum = sum + p[i];
    }
    return (double)sum / n;
}