#include<stdio.h>

void main()
{
	int i,pos,n;
	printf("Enter Any array Size....\n");
	scanf("%d",&n);
	
	printf("Enter any Position to delete perticular element...\n");
	scanf("%d",&pos);
        int a[n];

	printf("Enter the elements to array...\n");

	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<n;i++)
	{
		if(i==pos-1)
		{
			continue;
		}
		printf("%d",a[i]);
	}
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
}
