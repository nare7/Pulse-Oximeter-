//Input angles of a triangle and check whether triangel is valid or not
#include <stdio.h>
void main()
{
    int a, b, c;
    printf("Enter three angles of triangle:\n");
    scanf("%d %d %d", &a, &b, &c);
    if ((a + b + c) == 180 && (a > 0) && (b > 0) && (c > 0))
    {
        printf("Valid Triangle\n");
    }
    else
    {
        printf("Invalid Triangle\n");
    }
}
