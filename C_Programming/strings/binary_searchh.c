// binary search
	
#include <stdio.h>

void main()
{
	int n, flag =0;
	printf("enter the size of an array\n");
	scanf("%d", &n);
	int a[n];

	int i, j, low =0, high= n-1, mid, temp, key;
	
	printf("enter the %d array elements\n", n);
	for(i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	//enter key
	printf("enter the key to be found\n");
	scanf("%d", &key);

	//sorting
	for(j=0; j<n; j++)
	{
		for(i=0; i<n-j; i++)
		{
			if(a[i]>a[i+1])
			{
				temp = a[i];
				a[i]= a[i+1];
				a[i+1]= temp;
			}
		}
	}
	
	//printing sorting elements
	printf("elements after sorting ");
	for(i=0; i<n; i++)
	{
		printf("%d ", a[i]);
	}
	
	printf("\n");


	//binary search
	for( ; high>=low ; )
	{
		mid = (high + low)/2;
		if(a[mid] == key)
		{
			flag =1;
			printf("key is found %d", a[mid]);
			break;
		}
		else if(key >a[mid])
		{
			low = mid+1;
		}
		else
		{
			high = mid -1;
		}
	}
	if(flag == 0)
	{
		printf("key is not found\n");
	}
	
	
}

	
