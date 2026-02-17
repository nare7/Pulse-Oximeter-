//53. Write a C program to print all alphabets from a to z. - using while loop
#include<stdio.h>

void main()
{
	char ch;
	ch = 'a';
	printf("All Alphabets from a to z...\n");
	while(ch<='z')
	{
		printf("%c\n",ch);
		ch++;
	}
}

