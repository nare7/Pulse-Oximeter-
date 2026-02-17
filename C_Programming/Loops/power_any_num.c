//73. Write a C program to find power of any number using for loop.
#include<stdio.h>
void main()
{
	int base,exponent,result = 1;
	printf("Enter Base and Exponent...\n");
	scanf("%d%d",&base, &exponent);
	for(int i=0;i<exponent;i++)
	{
		result = result * base;
	}
	printf("%d is raised to power of %d is %d\n",base, exponent, result);
}
		
