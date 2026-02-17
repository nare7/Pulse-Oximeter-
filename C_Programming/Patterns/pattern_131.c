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
            		if(i == j || i + j == 4)
                		printf("1 ");
            		else
                	printf("0 ");
       		}
        	printf("\n");
    	}
    	printf("\n");
}
