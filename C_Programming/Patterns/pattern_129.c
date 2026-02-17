#include<stdio.h>
void main()
{
	int n;
	printf("Enter the no of Rows....\n");
	scanf("%d",&n);
	 
	for(int i = 0; i < n; i++) 
	{
        	for(int j = 0; j < n; j++) 
		{
            		printf("%d ", (i + j) % 2);
        }
        printf("\n");
    }
    printf("\n");
}
