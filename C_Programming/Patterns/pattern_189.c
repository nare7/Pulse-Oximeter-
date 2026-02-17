#include<stdio.h>
void main()
{
    int n;
    printf("Enter the no of rows...\n");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
	for(int k=1;k<=i;k++)
	{
		printf("*");
	}
        printf("\n");
    }
}
