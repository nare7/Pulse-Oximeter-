#include<stdio.h>

void main()
{
	int n,i;

	printf("Binary Search...\n");

	printf("Enter the any array size...\n");
	scanf("%d",&n);

	int a[n],low=0,high = n-1,key,flag = 0,pos = -1;
	
	printf("Enter any array values...\n");
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	printf("Enter any Key to check found or not...\n");
	scanf("%d",&key);
	
	while(low <= high)
	{
		int mid = (low + high)/2;
		if(a[mid] == key)
		{
			flag = 1;
			pos = mid;
			break;
		}
		else if(a[mid] < key)
		{
			low = mid + 1;
		}
		else
		{
			high = mid -1;
		}
	}
	if(pos == -1)
	{
		printf("Key is not found\n");
	}
	else
	{
		printf("Key is found index ...%d,%d\n",pos,key);
	}
}










	
	

