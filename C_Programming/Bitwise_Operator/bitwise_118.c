//118.Write a C program to count leading zeros in a binary number.
#include<stdio.h>
void main()
{
	int num,count=0;
	printf("Enter any number:\n");
	scanf("%d",&num);
	for(int i = sizeof(int)*8-1;i>=0;i--)
	{
		if((num &(1<<i))==0)
		{
			
			count++;
		}
		else
		{
			break;
		}
		
	}
	printf("leading Zeros...:%d\n",count);
}
