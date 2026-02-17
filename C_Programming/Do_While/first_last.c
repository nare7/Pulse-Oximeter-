//62. Write a C program to find first and last digit of any number.
#include <stdio.h>
void main()
{
	int num, last_digit, first_digit;
	printf("enter any number\n");
	scanf("%d", &num);
		
	last_digit = num%10;

	do{

		 first_digit = num%10;
		num=num/10;
		
	}
	while(num>0);
	printf("first number is %d\nlast numner is %d\n", first_digit, last_digit);
}
