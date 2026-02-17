#include<stdio.h>

void main()
{
	int num1,num2;
	printf("Enter any two numbers...\n");
	scanf("%d%d",&num1,&num2);
	printf("Before swaping num1 : %d , num2 = %d\n",num1,num2);
	//num1=num1+num2-(num2=num1);
	num1=num1^num2^(num2=num1);
	//num1=num1*num2/(num2=num1);
	printf("After swaping num1 : %d , num2 = %d\n",num1,num2);
}
