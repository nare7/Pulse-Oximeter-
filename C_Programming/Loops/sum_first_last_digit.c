//63. Write a C program to find sum of first and last digit of any number.
#include<stdio.h>
void main()
{
	int num,first_digit,last_digit,sum;
	printf("Enter any number....\n");
	scanf("%d",&num);
	int org_num = num;
	last_digit=num%10;
	while(num>0)
	{
		first_digit=num%10;
		num = num/10;
	}
	/*first_digit=num;
	
	while(first_digit>=10)
	{
		first_digit = first_digit/10;
	}*/
	sum = first_digit+last_digit;
	printf("First digit in a number : %d , first_digit : %d, Last_digit : %d\n, sum : %d\n",org_num,first_digit,last_digit,sum);
}
