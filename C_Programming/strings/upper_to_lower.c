//Write a C program to convert uppercase string to lowercase.

#include <stdio.h>

void main()
{
	int i;
	char str1[100], str2[100];
	printf("enter the string1\n");
	scanf("%s", str1);
	
	for(i=0; str1[i] !='\0'; i++)
	{
		if(str1[i]>='A' && str1[i]<='Z')
		{
			str2[i]= str1[i]+32;
		}
		printf("%c", str2[i]);
		
	}
	
}
