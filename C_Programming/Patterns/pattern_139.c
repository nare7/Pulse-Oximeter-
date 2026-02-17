#include<stdio.h>
void main()
{
	int n,i,j,k;
	printf("Enter no of rows...\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		k=i;
		for(j=1;j<=n;j++)
		{
			if(i+j<=n+1)
			{
				printf("%d",k++);
			}
		} 
		k=i-1;
		for(j=1;j<i;j++)
		{
			printf("%d", k--);
		}
		printf("\n");
	}
}
