#include<stdio.h>
void main()
{
	int i,j,n;
	printf("Enter the no of rows...\n");
	scanf("%d",&n);
	for(i=3;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i+j>=n+1)
				printf("*");
			else
				printf(" ");
		}
		for(j=1;j<=n;j++)
		{
			if(i>j)
				printf("*");
			else
				printf(" ");
		}
		for(j=1;j<=n;j++)
		{
			if(i+j>=n+1)
				printf("*");
			else
				printf(" ");
		}
		for(j=1;j<=n;j++)
		{
			if(i>j)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");


		//printf("\n");
        }
	n= n * 2;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i<j)
				printf("*");
			else
				printf(" ");
		}
		for(j=1;j<=n;j++)
		{
			if(i+j<=n+1)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}


			
			
