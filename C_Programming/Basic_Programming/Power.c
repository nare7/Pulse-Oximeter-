#include<stdio.h>
#include<math.h>
void main()
{
	unsigned int x,y,result;
	printf("Enter the X and Y Values :\n");
	scanf("%d%d",&x,&y);
	result = pow(x,y);
	printf("Power of X : %d And Y %d : %d\n",x,y,result);
}

