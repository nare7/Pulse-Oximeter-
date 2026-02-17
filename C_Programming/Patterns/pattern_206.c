#include<stdio.h>
void main()
{
	int i,j,n;
	printf("Enter the no of rows....\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i>=j)
				printf(" ");
		}
		for(j=1;j<=n;j++)
		{
			if(i+j<=n+1)
				printf("*");
		}
		printf("\n");
	}
	for(i=2;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i+j<=n+1)
				printf(" ");
		}
		for(j=1;j<=n;j++)
		{
			if(i>=j)
				printf("*");
		}
		printf("\n");
	}
	//printf("\n");

}
