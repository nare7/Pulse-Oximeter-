#include<stdio.h>
void swap(int a,int b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	
	printf("After Swaping a = %d\t,b = %d\n",a,b);
}
