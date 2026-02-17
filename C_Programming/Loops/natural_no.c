//51. Write a C program to print all natural numbers from 1 to n. - using while loop

#include<stdio.h>
void main()
{
	int n,i;
	printf("Enter any n values....\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("%d\n",i);
	}
}
