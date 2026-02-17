//214.Write a C program to find sum of all array elements.
#include<stdio.h>
void main()
{
	int n,i,sum = 0;
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
	
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
		sum = sum + a[i];

	}
	printf("sum of all array elements : %d\n",sum);
	
}

