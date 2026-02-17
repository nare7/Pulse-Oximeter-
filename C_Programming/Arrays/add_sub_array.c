// 1-D Array Perform ADD and SUB.....

#include<stdio.h>
void main()
{
	int n,i;
	printf("Enter the size...\n");
	scanf("%d",&n);

	int a[n],b[n],sum[n],sub[n];
	printf("Enter the array elements....\n");

	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}

	
	for(i=0;i<n;i++)
	{
		printf("%d \n",a[i]);
	}
	for(i=0;i<n;i++)
	{
		printf("%d\n",b[i]);
	}
	for(i=0;i<n;i++)
	{
		sum[i]=a[i] + b[i];
		sub[i]=a[i]-b[i];
		printf("Addition of 1 - D Array...%d\n",sum[i]);
		printf("Subtraction of 1 - D Array...%d\n",sub[i]);

	}
	//printf("Addition of 1 - D Array...%d\n",sum[i]);
	//printf("Subtraction of 1 - D Array...%d\n",sub[i]);



}
