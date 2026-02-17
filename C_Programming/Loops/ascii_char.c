//72. Write a C program to print all ASCII character with their values


#include<stdio.h>
void main()
{
	int n;
	printf("Enter any number..\n");
	scanf("%d",&n);
	while(n<=255)
	{
		printf("Ascii Values : %c , Decimal : %d , Hexa : %x , Binary : %b\n",n,n,n,n);
		n++;
	}
}
