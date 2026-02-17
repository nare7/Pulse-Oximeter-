//53. Write a C program to print all alphabets from a to z. - using while loop
#include <stdio.h>
void main()
{
	char ch=97;
	do
	{
		printf("%c ", ch);
		ch++;
	}while(ch<123);
printf("\n");
}

