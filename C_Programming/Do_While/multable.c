//59. Write a C program to print multiplication table of any number.
#include <stdio.h>
void main()
{
	unsigned int num, i=0;
	printf("enter any number for multiplication table\n");
	scanf("%d", &num);
	do
	{
		printf("%d * %d = %d\n", num, i, num*i);
		i=i+1;
	}
	while(i<=10);
}
