#include<stdio.h>
void main()
{
	unsigned int base,height;
	float area_triangle;
	printf("Enter the Base and Height Of a Triangle :\n");
	scanf("%d%d",&base,&height);
	area_triangle = 0.5 * base * height;
	printf("Area of Triangle : %f\n",area_triangle);
}
