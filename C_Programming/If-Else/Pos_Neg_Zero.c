#include<stdio.h>
void main()
{
	int num;
	printf("Enter any number:\n");
	scanf("%d",&num);
	if(num>0)
	{
		printf("%d : given number is Positive\n",num);
	}
	else if(num<0)
	{
		printf("%d : given number is Negitive\n",num);
	}
	else
	{
		printf("%d : Zero\n",num);
	}
}
