#include<stdio.h>
void main()
{
	unsigned int length, breadth,area_of_rectangle;
	printf("Enter the Lenght and Breadth of a Rectangle :\n");
	scanf("%d%d",&length,&breadth);
	area_of_rectangle = length * breadth;
	printf("Area Of Rectangle : %d\n",area_of_rectangle);
}
