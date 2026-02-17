#include<stdio.h>
void main()
{
	int n;
	printf("Enter the no of rows...\n");
	scanf("%d",&n);
	for(int i = 1; i <= n; i++) 
	{
        	for(int j = 0; j < n; j++) 
		{
            		printf("%d ", i);
        	}
        	printf("\n");
    	}
    	printf("\n");
}
