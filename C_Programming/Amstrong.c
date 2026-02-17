#include<stdio.h>
#include<math.h>
void main()
{
	int n,num,result=0,reminder,digit=0;
	printf("Enter any number....\n");
	scanf("%d",&num);
	int original = num;
	for(n=num;n!=0;n/=10)
	{
		digit++;
	}
	for(n=num;n!=0;n/=10)
	{

		reminder = n%10;
		result=result+pow(reminder,digit);
	}
	if(original==result)
	printf("The given no is amstrong num.. ");
	else
	printf("Not Amstrong num");
}
	
