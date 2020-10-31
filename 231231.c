#include <stdio.h> 
int main() 
{ 
    char str[80]; 
    int a;
    scanf("%d%[^ ]",&a,str); //读到'\n'结束读取
    printf("%d %s",a,str);
    return 0; 
}