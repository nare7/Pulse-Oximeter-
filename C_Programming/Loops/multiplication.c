//59. Write a C program to print multiplication table of any number.
#include<stdio.h>
void main()
{
	int n,i;
	printf("Enter any number...\n");
	scanf("%d",&n);
	printf("Multiplication Table....\n");
	for(i=1;i<=20;i++)
	{
		printf("%d * %2d = %2d\n",n,i,n*i);
	}
}
