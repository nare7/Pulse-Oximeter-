#include<stdio.h>
void main()
{
	int n;
	printf("Enter the no of rows...\n");
	scanf("%d",&n);
	for(int i = 0; i < n; i++) 
	{
        	for(int j = 0; j < n; j++) 
		{
            		if((i == 0 && j >= 1 && j <= 3) || 
               			(i == 4 && j >= 1 && j <= 3) ||
               			((i == 1 || i == 2 || i == 3) && (j == 0 || j == 4)))
                		printf("1 ");
            		else
                		printf("0 ");
        	}
        	printf("\n");
    	}
    	printf("\n");
}
