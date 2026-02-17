//71. Write a C program to enter any number and print it in words.
#include<stdio.h>
void main()
{
	int n;
	printf("Enter any number..\n");
	scanf("%d",&n);
	while(n<=255)
	{
		printf("%c",n);
	}
}
