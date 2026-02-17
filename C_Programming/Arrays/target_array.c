#include<stdio.h>

void main()
{
	int n,i;
	
	printf("Enter the any array size....\n");
	scanf("%d",&n);

	int a[n],target = 9,pos = -1;
	
	printf("Enter the array elements....\n");
	 
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<n;i++)
	{
		if(a[i] + a[i+1] == target)
		{
			printf("%d,%d\n = %d",a[i],a[i+1],target);
		}
		else
			printf("Target not found...\n");
		
	}
}
	
	
