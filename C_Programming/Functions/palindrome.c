#include<stdio.h>
void palindrome(int num1)
{
	int temp = num1,digit,rev_num=0;
	while(num1>0)
	{
		digit = num1 % 10;
		rev_num = rev_num * 10 + digit;
		num1 = num1 / 10;
		printf("reverse no .... %d\n",rev_num);
	}
	if(rev_num == temp)
	{
		printf("The given number is palindrome...\n");
	
	}
	else
	{
		printf("Not a Palindrome....\n");
	}

}
/*if(rev_no == temp)
{
	printf("The given number is palindrome...\n");
	
}
else
{
	printf("Not a Palindrome....\n");
}*/

