//111.Write a C program to get nth bit of a number.
#include<stdio.h>
void main()
{
	int num;
	printf("Enter the any number...\n");
	scanf("%d",&num);
	if(num&(1<<num-1))
	{
		printf("1");
	}
	else
	{
		printf("0");
	}
}
