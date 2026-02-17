#include<stdio.h>
void main()
{
	int n;
	printf("Enter the no of rows...\n");
	scanf("%d",&n);	
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=n-i;j++)
		{
			/*if(i==5 || j==1 || j==i)
			{
				printf("*");
			}
			else
			{*/
			printf(" ");
		}
		for(int j=1;j<=i;j++);
		{
			printf("*");
		}

		printf("\n");
	}
}
