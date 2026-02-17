#include<stdio.h>

void main()
{
	int n,key,flag=0,count=0,i;
	printf("Enter the any array size...\n");
	scanf("%d",&n);
	
	int a[n];
	printf("Enter the array values...\n");
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	printf("enter any key number to check...\n");
	scanf("%d",&key);
		

	for(i=0;i<n;i++)
	{
		if(key == a[i])
		{
			flag = 1;
			count ++;
		//	break;
		}
	}
	if(flag == 1)
	{
		printf("Key number is found...%d\n",key);
	}
	else
	{
		printf("Key number is not found... %d\n",key);
	}
	printf("Count (how many times repeat key found) ....%d\n",count);
}	
