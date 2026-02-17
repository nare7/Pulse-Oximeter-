//121.Write a C program to convert decimal to binary number system using bitwiseoperator.

#include<stdio.h>
void main()
{
	int decimal=0,binary,base=1,digit;
	printf("Enter the any binary number ....\n");
	scanf("%d",&binary);
	while(binary>0)
	{
		digit=binary%10;
		decimal=decimal+digit*base;
		base=base*2;
		binary = binary/10;
	}
	printf("%d : decimal number..\n",decimal);
}

	
