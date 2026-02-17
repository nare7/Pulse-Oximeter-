//116.Write a C program to get lowest set bit of a number.
#include<stdio.h>

void main()
{
	int num;
	printf("Enter any number...\n");
	scanf("%d",&num);
	int pos = -1;
	for(int i=0;i<sizeof(int)*8;i++)
	{
		if(num &(1<<i))
		{
			pos = i;
			break;
		}
	}
	printf("Lowest set bit position: %d\n",pos);
}
