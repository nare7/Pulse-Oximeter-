#include<stdio.h>
#include<math.h>
#define PI 3.14
void main()
{
	int i,n;
	float x,x1,den,sinx,sinval,term,acc;
	printf("Enter how many terms you want....\n");
	scanf("%d",&n);
	printf("Enter the Accuracy Value...\n");
	scanf("%f",&acc);
	printf("Enter any Degree...\n");
	scanf("%f",&x);
	x1=(PI * x)/180.0;
	sinx=sin(x1);
	term = x1;
	sinval=term;
	i=1;
	do
	{
		den = (2*i)*(2*i + 1);
		term = (-term * x1 * x1)/den;
		sinval = sinval+term;
		i++;
	}while(i<=n);
	printf("%f : Calculated Value...\n",sinval);
	printf("%f : Library value...\n",sinx);
}

