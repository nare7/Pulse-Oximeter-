#include<stdio.h>
void gcd(int num1, int num2)
{
	int numerator,denominator,rem,gcd;
	if(num1<num2)
	{
		numerator = num2;
		denominator = num1;
	}
	else
	{
		numerator = num1;
		denominator = num2;
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
	//lcm = num1*num2/gcd;
	//printf("Lcm of given numbers...: %d\n",lcm);
}		
