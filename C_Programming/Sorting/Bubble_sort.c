#include<stdio.h>

void main()
{
	int n,i;

	printf("Bubble Sort ...\n");

	printf("Enter the any array size...\n");
	scanf("%d",&n);

	int a[n],temp;
	
	printf("Enter any array values...\n");
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int j=0;j<n;j++)
	{
		for(i=0;i<n-j-1;i++)
		{
			
			if(a[i]>a[i+1])
			{
				temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}

}










	
	

