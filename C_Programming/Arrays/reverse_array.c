// Reverseing Array 


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
	printf("The Array....\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	printf(" Reverse Array....\n");
	for(i=n-1;i>=0;i--)
	{
		printf("%d\n",a[i]);
	}
	

	
}
