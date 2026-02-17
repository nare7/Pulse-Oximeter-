#include<stdio.h>
void main()
{
	int n;
	printf("enter the no of rows...\n");
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(i%2==0)
			{
				printf("0");
			}
			else
			{
				printf("1");
			}
			//printf("*");
		}
		printf("\n");
	}
}
