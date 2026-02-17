//58. Write a C program to find sum of all odd numbers between 1 to n.
#include <stdio.h>
void main()
{
	unsigned int num, i=0, sum_of_odd =0;
	printf("enter any number\n");
	scanf("%d", &num);
	do 
	{
		if(i % 2 == 1)
		{
			sum_of_odd = sum_of_odd + i;
		}
			i++;
	}
	while(i<=num);
	printf("sum of odd is %d\n", sum_of_odd);
}
