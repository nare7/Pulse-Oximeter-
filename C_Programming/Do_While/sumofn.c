//56. Write a C program to find sum of all natural numbers between 1 to n.
#include <stdio.h>
void main()
{
	int n, i=1, sum=0;
	printf("enter any number\n");
	scanf("%d", &n);
	do
	{
		sum = sum + i;
		i++;
	}
	while(i<=n);
	
	printf("sum is %d\n", sum);
}
	
	
