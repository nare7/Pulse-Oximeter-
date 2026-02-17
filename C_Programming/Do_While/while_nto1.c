//Write a C program to print all natural numbers in reverse (from n to 1). - using do while
//loop
#include <stdio.h>
void main()
{
	int n;
	printf("enter any number\n");
	scanf("%d", &n);
	printf("numbers in reverse order\n");
	do 
	{
		printf("%d ", n);
		n--;
	}while(n>=1);
}
