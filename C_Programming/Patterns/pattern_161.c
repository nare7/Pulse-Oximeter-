#include<stdio.h>

void main()
{
	int i,n,j;
	printf("enter the no of rows...\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			if(j==1 || i==j || i==n )
			{
				printf("1");
			}
			else
			{
				printf("0");
			}
		}
		printf("\n");
	}
}
