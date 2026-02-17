#include<stdio.h>
void main()
{
	int n;
	printf("Enter the no rows ...\n");
	scanf("%d",&n);
	for(int i = 0; i < n; i++) 
	{
        	for(int j = 0; j < n; j++) 
		{
            		if(i == 2 || j == 2)
                	printf("0 ");
            	else
                	printf("1 ");
        	}
      		printf("\n");
    	}
    	printf("\n");
}
