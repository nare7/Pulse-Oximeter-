#include<stdio.h>
void allprimeSum(int m)
{
	int n,isPrime=1,sum=0;
	//printf("Enter The Range(0-n)\n");
	//scanf("%d",&n);
	for(int i=2;i<=m;i++)
	{
		//isPrime = 1;
		for(int j=2;j<=i/2;j++)
		{
			if(i%j==0)
			{
				isPrime = 0;
				break;
			}
		}
		if(isPrime)
		{
			sum = sum + i;
		//printf("Count prime numbers %d\n",count);
		}
        }
	printf("sum of prime numbers %d\n",sum);


}
	
