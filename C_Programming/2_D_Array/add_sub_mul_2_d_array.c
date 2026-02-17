#include<stdio.h>

void main()
{
	int row1,col1,row2,col2,i,j,k;
	printf("Enter the rows and columns....\n");
	scanf("%d%d%d%d",&row1,&col1,&row2,&col2);
	
	int a[row1][col1],b[row2][col2],result[row1][col2];
	
	printf("Enter the first matrix...\n");
	
	for(i=0;i<row1;i++)
	{
		for(j=0;j<col1;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	printf("Enter the second matrix...\n");

	
	for(i=0;i<row1;i++)
	{
		for(j=0;j<col1;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}

	printf("Multiplication of 2-D Matrix ....\n");


	for(i=0;i<row1;i++)
	{
		for(j=0;j<col2;j++)
		{
			result[i][j] = 0;
			for(k=0;k<col1;k++)
			{
				result[i][j] = result[i][j] + a[i][j] * b[i][j];
			}
		}
	}
	
	printf("Result Matrix of 2-D array....\n");
	
	for(i=0;i<row1;i++)
	{
		for(j=0;j<col2;j++)
		{
			printf("%d",result[i][j]);
		}
		printf("\n");
	}
}
	

	
	
	
