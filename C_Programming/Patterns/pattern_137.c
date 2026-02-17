#include<stdio.h>
void main()
{
	int i,j,n;
	printf("Enter the no of rows...\n");
	scanf("%d",&n);
	for(i=n;i>=1;i--)
	{
		for(j=n;j>=i;j--)
		{
			printf("%d",j);
		}
		for(j=n-1;j>n-i;j--)
		{
			printf("%d",i);
		}
		
		printf("\n");
	}
}
			
