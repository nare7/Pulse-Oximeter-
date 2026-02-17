//Write a C program to print all natural numbers from 1 to n. - using do while loop
#include <stdio.h>
void main()
{
	int n, i=1;
	printf("enter any number\n");
	scanf("%d", &n);
	printf("natutral numbers till %d are\n", n);
	do
	{
		printf("%d\n", i);
		i++;
	}
	while(i<=n);
}
