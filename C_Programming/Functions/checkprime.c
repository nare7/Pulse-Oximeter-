#include<stdio.h>
void checkPrime(int num1)
{
	int isPrime = 1;
	if(num1 <=1)
	{
		printf("%d is not a prime number\n",num1);
	}
	for(int i=2;i<=num1/2;i++)
	{
		if(num1%i==0)
		{
			isPrime = 0;
			break;
		}
	}
	if(isPrime)
	{
		printf("%d is a prime number\n",num1);
	}
	else
	{
																		printf("%d is  not a prime number\n",num1);
	}

	//printf("%d is a prime number\n",n);
}
