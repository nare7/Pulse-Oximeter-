#include<stdio.h>
void main()
{
	int rows;
	printf("Enter the no of rows....\n");
	scanf("%d",&rows);
	for(int i=rows;i>=1;i--)
	{
		for (int j=rows;j>=1;j--)
		{
			printf("%d",j);
		}
		printf("\n");
	}
}
