//122.Write a C program to swap two numbers using bitwise operator.
#include<stdio.h>
void main()
{
	int num1,num2;
	printf("Enter num1 and num2 numbers....\n");
	scanf("%d%d",&num1,&num2);
	printf("Before swaping ...num1 = %d,num2 = %d",num1,num2);

	num1=num1^num2;
	num2=num1^num2;
	num1=num1^num2;
	
	printf("After Swaping .....num1 = %d,num2=%d\n",num1,num2);
}
