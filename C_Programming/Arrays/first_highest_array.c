#include<stdio.h>
void main()
{
	int n,i,max;
	printf("Enter the size...\n");
	scanf("%d",&n);

	//printf("Enter the size...\n");
	//scanf("%d",&key);

	int a[n];
	printf("Enter the array elements....\n");

	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	max = a[0];
	
	for(i=0;i<n;i++)

	{
		if(max<a[i])
		{
			max = a[i];
		}
	}
	printf("First highest number : %d ",max);
	
}

