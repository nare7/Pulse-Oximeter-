#include<stdio.h>
void main()
{
	int i,j,n,k;
	printf("Enter no of rows...\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		k=i;
		for(j=1;j<=n-i+1;j++)
		{
			printf("%d",k++);
			
		}
		for(j=1;j<=i;j++)
		{
			printf("%d",n);
		}
		printf("\n");
	}
}
