#include<stdio.h>
void main()
{
	int n,i,pos,element;
	printf("Enter the size...\n");
	scanf("%d",&n);

	int a[n];
	printf("Enter the array elements....\n");

	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the position ....");
	scanf("%d",&pos);
	printf("Enter any element to the array...");
	scanf("%d",&element);

// inserting element in array in any location 
// first creating space to perticular position 
	for(i=0;i>=pos;i--)
	{
		a[i] = a[i-1];
	}
	
	a[pos -1] = element;
	printf("Updated Array..\n");

	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	
}
