//66. Write a C program to calculate product of digits of any number.


#include<stdio.h>
void main()
{
	int num,product=1;
	printf("Enter any number...\n");
	scanf("%d",&num);
//	printf("Sum of digit in a number: %d\n",num);
	while(num>0)
	{
		int digit = num % 10;
		product*=digit;
		num = num/10;
	}
	printf("Product Of digit : %d\n",product);
}
