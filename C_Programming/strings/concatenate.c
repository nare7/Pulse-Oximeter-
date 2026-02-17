//Write a C program to concatenate two strings.
	
#include <stdio.h>

void main()
{
	int i, j, count=0;
	char str1[]= {"sai"};
	char str2[]= {"srinivas"};
	for(i=0; str1[i] !=0; i++)
	{
		count++;
	}
	for(j=0; str2[j] !=0; j++)
	{
		str1[j+count] = str2[j];
	}
	printf("concatenated string is %s\n", str1);
}
