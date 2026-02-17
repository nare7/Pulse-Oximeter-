#include<stdio.h>
void main()
{
	int n;
	printf("Enter the no of rows...\n");
	scanf("%d",&n);
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i+j>=n+1)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(i>j)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(i+j>=n+1)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(i>j)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		/*for(int j=1;j<=n;j++)
		{
			if(i+j>=n+1)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(i>j)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}*/

		printf("\n");
	}
	n=n+n;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i<=j)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		for(int j=1;j<=n;j++)
		{
			
			if(i+j<=n+1)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

			



	
