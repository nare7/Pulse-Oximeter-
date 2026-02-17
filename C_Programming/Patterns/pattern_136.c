#include<stdio.h>
void main()
{
	int n,num=1;
	printf("Enter the no of rows...\n");
	scanf("%d",&n);
	for(int i = 1; i <= n; i++) 
	{
        	for(int j = 0; j <= n; j++) 
		{
            		printf("%d ", num);
			num++;
        	}
        	printf("\n");
    	}
    	printf("\n");
}
