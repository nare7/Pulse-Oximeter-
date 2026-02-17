//215.Write a C program to find maximum and minimum element in an array.

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
	
	int max = a[0];
	int min = a[0];

	
	for(i=0;i<n;i++)
	{
		if(a[i]>max)
		{
			max = a[i];
		}
		if(a[i]<min)
		{
			min = a[i];
		//else if(
		//printf("%d",max);
         	}
        }
	printf("Maximum Number in given array : %d\n",max);
	printf("Minimum Number in given array : %d\n",min);
	
}
