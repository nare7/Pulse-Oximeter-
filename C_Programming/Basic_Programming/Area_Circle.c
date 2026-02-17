#include<stdio.h>
#define pi 3.14
void main()
{
	unsigned int r; // r - radius
	float area_of_circle; // or declare pi = 3.14
	printf("Enter the radius of Circle :\n");
	scanf("%d",&r);
	area_of_circle = pi * r * r;
	printf("Area of Circle : %f\n",area_of_circle);
}

	
