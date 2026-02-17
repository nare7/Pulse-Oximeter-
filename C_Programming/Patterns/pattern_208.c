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
			if(i==j || i+j==n+1)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}
