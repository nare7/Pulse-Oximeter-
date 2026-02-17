//61. Write a C program to count number of digits in any number.
#include<stdio.h>
void main()
{
	int num,count=0,digit,org_num;
	printf("Enter any number...\n");
	scanf("%d",&num);
	org_num = num;
	while(num>0)
	{
		digit = num%10;
		num = num /10;
		count++;
	}
	printf("Digit count in number  : %d, count = %d\n",org_num, count);
}
