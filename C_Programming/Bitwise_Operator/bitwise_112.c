//112.Write a C program to set nth bit of a number.
#include<stdio.h>

void main()
{
	int num,n;
	printf("Enter any number and n:\n");
	scanf("%d%d",&num, &n);
	int set = num | (1<<n);
	printf("Set nth bit of a number: %d\n",set);
}	
