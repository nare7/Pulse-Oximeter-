#include<stdio.h>
void main()
{
	int n,isPrime=1;
	printf("Enter any number\n");
	scanf("%d",&n);
	if(n <=1)
	{
		printf("%d is not a prime number\n",n);
	}
	for(int i=2;i<=n/2;i++)
	{
		if(n%i==0)
		{
			isPrime = 0;
			break;
		}
	}
	if(isPrime)
	{
		printf("%d is a prime number\n",n);
	}
	else
	{
																		printf("%d is  not a prime number\n",n);
	}

	//printf("%d is a prime number\n",n);
}
