#include<stdio.h>
void main()
{
	unsigned int a,b;
	printf("Enter the values of a and b :\n");
	scanf("%d%d",&a,&b);
	printf("Addition : %d\n",a+b);
	printf("Subtraction : %d\n",a-b);
	printf("Multiplication : %d\n",a*b);
	printf("Division : %.2f\n",(float)a/b);
	printf("Modulus : %d\n",a%b);
}

