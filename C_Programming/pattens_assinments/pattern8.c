#include<stdio.h>
void main()
{
	int n;
	printf("enter the no of rows...\n");
	scanf("%d",&n);
	for(int i=5;i>=n;i--)
	{
		for(int j=5;j>=i;j--)
		{
			printf(" ");

		}
		for(int k=0;k<=i;k++)
		{
			printf("*");
		}
		printf("\n");
	}
}
