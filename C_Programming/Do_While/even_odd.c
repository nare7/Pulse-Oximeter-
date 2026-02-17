#include<stdio.h>
void main()
{
	unsigned int i,even_sum,odd_sum,n;
	printf("Enter any number in range(1-100)\n");
	scanf("%d",&n);
	i = 0;
	do
	{
		if(i%2==0)
		{
			even_sum = even_sum + i;
			printf("Even : %d\n",i);
		}
		else
		{
			odd_sum = odd_sum + i;
			printf("Odd : %d\n",i);
		}
		i++;
	}while(i<=n);
	printf("Even_Sum : %d\n",even_sum);
	printf("Odd_Sum : %d\n",odd_sum);
}
