//114.Write a C program to toggle nth bit of a number.
#include<stdio.h>

void main()
{
	int num,n;
	printf("Enter any number and n:\n");
	scanf("%d%d",&num, &n);
	int toggle = num | (1<<n);
	printf("toggle nth bit of a number: %d\n",toggle);
}	
