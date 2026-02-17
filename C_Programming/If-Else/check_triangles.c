//Write a C program to check whether the triangle is equilateral, isosceles or scalene triangle.
#include <stdio.h>
void main() 
{
    int a, b, c;
    printf("Enter any three sides of triangle:\n");
    scanf("%d%d%d",&a,&b,&c);
    if ((a+b>c) && (a+c>b) && (b+c>a)) 
    {
        if ((a==b) && (b==c))
        {
            printf("It is a Equilateral Triangle\n");
        }
        else if ((a==b) || (b==c) || (a==c))
	{
            printf("it is a Isosceles Triangle\n");
	}
        else
	{
            printf("It is a Scalene Triangle\n");
        }
    }
    else 
    {
        printf("Invalid Triangle\n");
    }

}
