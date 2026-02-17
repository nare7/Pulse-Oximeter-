//217.Write a C program to count total number of even and odd elements in an array.

#include<stdio.h>
void main()
{
	int n,i;
	printf("Enter the size...\n");
	scanf("%d",&n);

	int a[n],even[n],odd[n],even_count=0,odd_count=0;
	printf("Enter the array elements....\n");

	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<n;i++)
	{
		if(a[i] % 2 == 0)
		{
			even[even_count++] = a[i];
			//printf("Even : %d\n",even[i]);
		}
		else
		{
			odd[odd_count++] = a[i];
			//printf("Odd : %d\n",odd[i]);
		}
		//printf("%d",a[i]);
	}
	printf("Even numbers ....\n");
	for(i=0;i<even_count;i++)
	{
		printf("%d\n",even[i]);
	}
	printf("Even numbers ....\n");
	for(i=0;i<odd_count;i++)
	{
		printf("%d\n",odd[i]);
	}



	
}
