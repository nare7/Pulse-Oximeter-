#include<stdio.h>
void main()
{
	int n,i,j;
	printf("Enter the no of rows...\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n*2;j++)
		{
			if((j >= n-(i-1) && (j<=n+(i-1))) || i==n || j==i|| i==n)
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
