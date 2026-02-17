#include<stdio.h>
void main()
{
	int n;
	printf("enter the no of rows...\n");
	scanf("%d",&n);
	for(int i=5;i>=n;i--)
	{
		for(int j=i;j>=n;j--)
		{
			printf("*");
		}
		printf("\n");
	}
}
