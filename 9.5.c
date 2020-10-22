#include <stdio.h>
float F1(float x);
float F2(float x);
float Integral(float (*f)(float), float a, float b);
int main()
{
    float y1, y2;
    y1 = Integral(F1, 0.0, 1.0);
    y2 = Integral(F2, 0.0, 3.0);
    printf("y1 = %f,y2 = %f", y1, y2);
    return 0;
}
float F1(float x)
{
    return 1 + x * x;
}
float F2(float x)
{
    return x / (1 + x * x);
}
float Integral(float (*f)(float), float a, float b)
{
    float s, h;
    int n = 100, i;
    s = ((*f)(a) + (*f)(b)) / 2;
    h = (b - a) / n;
    for (i = 1; i < n; i++)
    {
        s += (*f)(a + i * h);
    }
    return s * h;
}