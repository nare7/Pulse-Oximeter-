//57. Write a C program to find sum of all odd numbers between 1 to n.
#include<stdio.h>
void main()
{
	int n,sum=0,i;
	printf("Enter any number....\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		if(i%2!=0)
		{
			sum += i;
		}
	}
	printf("Sum Of All Odd NUmbers : %d\n",sum);
}
