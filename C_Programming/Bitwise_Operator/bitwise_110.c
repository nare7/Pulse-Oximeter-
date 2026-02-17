//110.Write a C program to check Most Significant Bit (MSB) of a number is set or not.
#include<stdio.h>
void main()
{
	int num;
	printf("Enter any number...\n");
	scanf("%d",&num);
	int bits = sizeof(num)*8-1;
	if(num & (1<<bits))
	{
		printf("MSB is set : %d\n",num);
	}
	else
	{
		printf("LSB is not set : %d\n",num);
	}
}
