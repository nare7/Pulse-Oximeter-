//56. Write a C program to find sum of all natural numbers between 1 to n.
#include<stdio.h>
void main()
{
	int n,sum=0,i;
	printf("Enter any number....\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		sum += i;
	}
	printf("Sum Of All Natural NUmbers : %d\n",sum);
}
