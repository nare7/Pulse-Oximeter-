#include<stdio.h>
#define pi 3.14
void main()
{
	float r,diameter,circumference,area;
	printf("Enter the Radius Of Circle:\n ");
	scanf("%f\n",&r);
	diameter = 2*r;
	printf("Diameter :%f\n",diameter);
	circumference = 2 * pi * r;
	printf("Circumference : %f\n",circumference);
	area = pi * r * r;
	printf("Area Of Square :%f\n",area);
}
