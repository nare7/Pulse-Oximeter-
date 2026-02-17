//109.Write a C program to check Least Significant Bit (LSB) of a number is set or not.
#include<stdio.h>
void main()
{
	int num;
	printf("Enter any number...\n");
	scanf("%d",&num);
	if(num & 1)
	{
		printf("LSB bit is set...%d\n",num);
	}
	else
	{
		printf("LSB bit is not set...%d\n",num);
	}
}
