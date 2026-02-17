#include<stdio.h>
void main()
{
    int n;
    printf("Enter the no of rows...\n");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
	for(int j=1;j<=i;j++)
	{
		if((j==1 || i==n || i==j))
		{
			printf("*");
		}
		else
		{
			printf(" ");
		}
	}
        printf("\n");
    }
}
