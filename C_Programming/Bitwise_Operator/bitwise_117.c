//117.Write a C program to count trailing zeros in a binary number.
#include<stdio.h>
void main()
{
	int num,count=0;
	printf("Enter any number:\n");
	scanf("%d",&num);
	while((num & 1) == 0 && num != 0)
	{
		count++;
		num = num >>1;
	}
	printf("Trailing Zeros...:%d\n",count);
}
