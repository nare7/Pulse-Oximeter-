#include<stdio.h>

void main()
{
	int fib1=0,fib2=1,fib3,n,count=0;
	printf("Enter any n value...\n");
	scanf("%d",&n);
	printf("Fibonacci series.....\n");
	printf("%d%d\n",fib1,fib2);
	fib3=fib1+fib2;
	for(int i=0;i<=n;i++)
	{
		printf("%d\n",fib3);
		fib1=fib2;
		fib2=fib3;
		fib3=fib1+fib2;
		count++;

	}
	printf("Count: %d\n",count);
}
	
	
