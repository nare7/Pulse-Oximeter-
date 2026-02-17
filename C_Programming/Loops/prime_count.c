#include<stdio.h>
void main()
{
	int n,isPrime=1,count=0;
	printf("Enter The Range(0-n)\n");
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
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
			count++;
		//printf("Count prime numbers %d\n",count);
		}
}
	printf("Count prime numbers %d\n",count);


}
