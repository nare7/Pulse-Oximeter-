#include<stdio.h>
void prime(int n)
{	
	int isPrime=1;
	//printf("Enter any number\n");
	//scanf("%d",&n);
	//if(i <=1)
	//{
	//	printf("%d is not a prime number\n",n);
	//}
	for(int j=0;j<=n;j++)
	{
		isPrime = 1;
		for(int i=2;i<=j/2;i++)
		{
			if(j%i==0)
			{
				isPrime = 0;
				break;
			}
		}
		if(isPrime)
		{
			printf("%d",j);
		//printf("%d is a prime number\n",n);
		}	
	}
	printf("\n");
}

	//printf("%d is a prime number\n",n);
