//61. Write a C program to count number of digits in any number.
#include <stdio.h>
void main()
{
	int num, count=0;
	printf("enter any number\n");
	scanf("%d", &num);
	do
	{
		int digit = digit%10;
		num = num/10;
		count++;
	}
	while(num>0);
	printf("no of digits are %d\n", count);
}
