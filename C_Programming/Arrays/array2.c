#include<stdio.h>
void main()
{
	int n,i,key,flag=1;
	printf("Enter the size...\n");
	scanf("%d",&n);

	printf("Enter the size...\n");
	scanf("%d",&key);

	int a[n];
	printf("Enter the array elements....\n");

	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
		if(key == a[i])
		{
			flag = 1;
			break;
		}

	}
	if(flag == 1)
	{
		printf("Key is found : %d\n",key);
	}
	else
	{
		printf("Key is not found : %d\n",key);
	}
	
}
