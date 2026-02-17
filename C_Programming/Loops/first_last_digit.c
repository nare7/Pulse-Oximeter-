//62. Write a C program to find first and last digit of any number.
#include<stdio.h>
void main()
{
	int num,first_digit,last_digit;
	printf("Enter any number....\n");
	scanf("%d",&num);
	int org_num = num;
	last_digit=num%10;
	first_digit=num;
	
	while(first_digit>=10)
	{
		first_digit = first_digit/10;
	}
	printf("First digit in a number : %d , first_digit : %d, Last_digit : %d\n",org_num,first_digit,last_digit);
}
		
