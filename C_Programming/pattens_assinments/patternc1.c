#include<stdio.h>
void main()
{
	int rows,ch='A';
	printf("Enter the no of rows....\n");
	scanf("%d",&rows);
	for(int i=0;i<rows;i++)
	{
		for (int j=0;j<=i;j++)
		{
			printf("%c",ch);
		}
		printf("\n");
	}
} 
