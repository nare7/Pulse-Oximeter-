#include<stdio.h>
void main()
{
	int gcd,lcm,num1,num2,numerator,denominator,rem;
	printf("Enter any two numbers...\n");
	scanf("%d%d",&num1,&num2);
	if(num1>num2)
	{
		numerator = num1;
		denominator=num2;
	}
	else
	{
		numerator=num2;
		denominator=num1;
	}
	rem = numerator % denominator;
	while(rem!=0)
	{
		numerator=denominator;
		denominator=rem;
		rem=numerator % denominator;
	}
	gcd = denominator;
	printf("GCD of given numbers...: %d\n",gcd);
	lcm = num1*num2/gcd;
	printf("Lcm of given numbers...: %d\n",lcm);
}
