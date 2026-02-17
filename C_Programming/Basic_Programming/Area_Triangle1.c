#include<stdio.h>
#include<math.h>
void main()
{
	unsigned int a, b, c;
	float s,area_of_triangle;
	printf("Enter the Side Of a Triangle : \n");
	scanf("%d%d%d",&a,&b,&c);
	s = (a+b+c)/2;
	area_of_triangle = sqrt(s*(s-a)*(s-b)*(s-c));
	printf("Area Of Triangle : %f\n",area_of_triangle);
}	
