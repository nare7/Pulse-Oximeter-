//113.Write a C program to clear nth bit of a number.
#include<stdio.h>

void main()
{
	int num,n;
	printf("Enter any number and n:\n");
	scanf("%d%d",&num, &n);
	int clear = num & (~(1<<n));
	printf("Clear nth bit of a number: %d\n",clear);
}	

