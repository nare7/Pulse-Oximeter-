#include<stdio.h>
void main()
{
	int a,b,c;
	printf("Enter any three numbers:\n");
	scanf("%d%d%d",&a,&b,&c);
	if((a>b)&&(a>c))
	{
		printf("%d: A is greater\n",a);
	}
	else if((b>a)&&(b>c))
	{
		printf("%d: B is greater\n",b);
	}
	else
	{
		printf("%d: C is greater\n",c);
	}
}
