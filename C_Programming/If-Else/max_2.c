//Maximum between two number
#include <stdio.h>
void main() 
{
    int a, b;
    printf("Enter any two numbers:\n");
    scanf("%d %d", &a, &b);
    if (a > b)
    {
        printf("Maximum number  = %d\n", a);
    }
    else if (b > a)
    {
        printf("Maximum number = %d\n", b);
    }
    else
    {
        printf("Both are equal numbers \n");
    }
}
