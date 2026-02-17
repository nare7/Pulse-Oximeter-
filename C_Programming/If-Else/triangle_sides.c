#include <stdio.h>
void main() 
{
    int a,b,c;
    printf("Enter any three sides of triangle:\n");
    scanf("%d%d%d",&a,&b,&c);
    if ((a+b>c) && (a+c>b) && (b+c>a))
    {
        printf("It is a Valid Triangle\n");
    }
    else
    {
        printf("It is a Invalid Triangle\n");
    }
}
