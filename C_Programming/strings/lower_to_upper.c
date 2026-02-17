//Write a C program to convert lowercase string to uppercase.

#include <stdio.h>

void main()
{
	int i;
	char str1[100], str2[100];
	printf("enter the string1\n");
	scanf("%s", str1);

	
	for(i=0; str1[i] !='\0'; i++)
	{
		if(str1[i]>='a' && str1[i]<='z')
		{
			str2[i]= printf("%c", str1[i]-32);
			printf("%c", str2[i]);
		}
	}
}	
		
	
