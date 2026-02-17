#include<stdio.h>
#include "declare.h"

void main()
{
	int num1,num2,a,b,fib1=0,fib2=1,fib3,n,x,y,z,m,number;//,numerator,denominator,rem,lcm,gcd;
	printf("Enter the num1 & num2 ....\n");
	scanf("%d%d",&num1,&num2);
	printf("Enter the a & b values....\n");
	scanf("%d%d",&a,&b);
	
	printf("Before Swaping a = %d\t, b = %d\n",a,b);
	swap(a,b);
	gcd(num1,num2);
	printf("\n");
	printf("Fibonacci Seriess...\n");
	printf("%d%d",fib1,fib2);
	fibonacci(fib3);
	printf("\n");
	printf("Palindrome....\n");
	palindrome(num1);
	printf("\n");
	printf("Check The given number prime or not\n");
	checkPrime(num1);
	printf("\n");
	printf("Print 1-100 Prime Numbers...\n");
	printf("Enter the range ....\n");
	scanf("%d",&n);
	prime(n); 
	printf("\n");
	printf("Quadratic Eqations of roots....\n");
	printf("Enter any roots ,,,,,\n");
	scanf("%d%d%d",&x,&y,&z);
	quadratic(x,y,z);
	printf("\n");
	printf("The Sum of all prime numbers....\n");
	printf("Enter range....\n");
	scanf("%d",&m);
	allprimeSum(m);
	printf("\n");
	printf("Bitwise Operators Set_a_bit,Clear_a_bit,Toggle_a_bit....\n");
	printf("Enter any number....\n");
	scanf("%d",&number);

	//printf("enter ...\n");
	bitwise(number);

	//lcm(num1,num2);
}
	
