//54. Write a C program to print all even numbers between 1 to 100. - using while loop
#include<stdio.h>
void main()
{
	int n,i;
	printf("Enter any number ...\n");
	scanf("%d",&n);
	printf("All Even numbers btw 1 to n...\n");
	i=0;
	while(i<=n)
	{
		if(i % 2 == 0)
		{
			printf("%d\n",i);
		}
		i++;
	}

}
