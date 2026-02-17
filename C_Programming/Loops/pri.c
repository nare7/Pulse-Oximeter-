#include<stdio.h>
void main()
{
	int count = 0,n,m,i,j;
	printf("Enter the n and m valuesss....\n");
	scanf("%d%d",&n,&m);
	
	for(i=n;i<=m;i++)
	{
		for(j=2;j<=n/2;j++)
		{
			if(i%j==0)
			{
				count++;
				break;
			}
		}
		if(count == 0)
		{
			printf("%d",i);
		}
		count = 0; 
	}
}

