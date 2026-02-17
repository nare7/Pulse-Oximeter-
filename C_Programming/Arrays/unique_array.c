#include<stdio.h>
//#include<stdbool.h>

void main()
{
	int n,i,j,flag=1;
	printf("Enter any size of an array..\n");
	scanf("%d",&n);
	
	int a[n];
	
	printf("Enter array elements...\n");
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<n;i++)
	{

		flag = 1;
		for(j=0;j<n;j++)
		{
			if(i != j && a[i] == a[j])
			{
				flag = 0;
				break;
			}
		}
		if(flag)
		{
			printf("%d",a[i]);
		}
	}
	
			

}
