//52. Write a C program to print all natural numbers in reverse (from n to 1). - using while loop
#include<stdio.h>
void main()
{
	int n,i;
	printf("Enter any n values....\n");
	scanf("%d",&n);
	printf("All Natural Numbers reverse n to 1...\n");
	i=n;
	while(i>=1)
	{
		printf("%d\n",i);
		i--;
	}
}
