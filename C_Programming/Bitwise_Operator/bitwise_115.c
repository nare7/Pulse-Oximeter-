//115.Write a C program to get highest set bit of a number.
#include<stdio.h>
void main()
{
	int num;
	printf("Enter any number...\n");
	scanf("%d",&num);
	int pos = -1;
	for(int i=sizeof(int)*8-1;i>=0;i--)
	{
		if(num &(1<<i))
		{
			pos = i;
			break;
		}
	}
	printf("Highest Set bit position :%d\n",pos);
}
