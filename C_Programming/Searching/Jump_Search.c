#include<stdio.h>
#include<math.h>


void main()
{
	int n,i;

	printf("Jump Search...\n");

	printf("Enter the any array size...\n");
	scanf("%d",&n);

	int a[n],prev=0,step = sqrt(n),key,flag = 0,pos = -1;
	
	printf("Enter any array values...\n");
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	printf("Enter any Key to check found or not...\n");
	scanf("%d",&key);
	
	while(step < n && a[step - 1] < key)
	{
		prev = step;
		step = step + sqrt(n);
		
		if(prev >= n)
		{
			//flag = 1;
			//pos = mid;
			break;
		}
	}
	if(step > n)
	{
		step  = n;
	}
	for(i=prev; i<step;i++)
	{
		if(a[i] == key)
		{
			pos = i;
			break;
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










	
	

