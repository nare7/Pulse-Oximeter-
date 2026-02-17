//65. Write a C program to calculate sum of digits of any number.

#include<stdio.h>
void main()
{
	int num,sum=0;
	printf("Enter any number...\n");
	scanf("%d",&num);
	printf("Sum of digit in a number: %d\n",num);
	while(num>0)
	{
		int digit = num % 10;
		sum+=digit;
		num = num/10;
	}
	printf("Sum Of digit : %d\n",sum);
}
