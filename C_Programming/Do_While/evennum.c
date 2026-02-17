//54. Write a C program to print all even numbers between 1 to 100. - using do while loop
#include <stdio.h>
void main()
{
	int num, even=2;
	printf("enter any number\n");
	scanf("%d", &num);
	do
	{
		printf("%d ", even);
		even +=2;
	}while(even <= num);
	printf("\n");
}

