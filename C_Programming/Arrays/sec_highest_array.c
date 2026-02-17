//216.Write a C program to find second largest element in an array.

#include<stdio.h>
void main()
{
	int n,i,max,sec_high;
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
	sec_high = -1;
	
	for(i=0;i<n;i++)

	{
		if(max<a[i])
		{
			sec_high = max;
			max = a[i];
		}
		else if (a[i]>sec_high && a[i] != max)

		{
			sec_high = a[i];
		}

			
	}
	printf("First highest number : %d\n",max);
	printf("Second highest number : %d\n",sec_high);
	
}

