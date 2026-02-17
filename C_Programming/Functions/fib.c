#include<stdio.h>
void fibonacci(int fib3)
{
	int fib1=0,fib2=1,n=10;//,fib3;
	fib3=fib1+fib2;
	for(int i=0;i<=n;i++)
	{
		printf("%d\n",fib3);
		fib1=fib2;
		fib2=fib3;
		fib3=fib1+fib2;
		//count++;

	}
}

