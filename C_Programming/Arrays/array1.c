#include<stdio.h>
void main()
{
	int n,i;
	printf("Enter the size...\n");
	scanf("%d",&n);

	int a[n];
	printf("Enter the array elements....\n");

	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	
}
