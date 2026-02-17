//55. Write a C program to print all odd number between 1 to 100.
#include <stdio.h>
void main()
{
	int num, odd=1;
	printf("enter any number\n");
	scanf("%d", &num);
	do
	{
		printf("%d ", odd);
		odd += 2;
	}while(odd <= num);
	printf("\n");
}
	
