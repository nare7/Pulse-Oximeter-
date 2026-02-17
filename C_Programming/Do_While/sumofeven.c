//57. Write a C program to find sum of all even numbers between 1 to n.
#include <stdio.h>
void main()
{
	int num, sum_of_even = 0, a=1;
	printf("enter the any number\n");
	scanf("%d", &num);
	do
	{
		if(a % 2==0)
		{
			sum_of_even = sum_of_even + a;
		}
		a++;
	}while(a<=num);
	printf("sum of even numbers is %d\n", sum_of_even);
}
