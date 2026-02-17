//Write a C program to compare two strings.
	
#include <stdio.h>

void main()
{
	int i, k, flag =0;
	char str1[100], str2[100];
	printf("enter the string1\n");
	scanf("%s", str1);

	printf("enter the string2\n");
	scanf("%s", str2);
	for(i=0; str1[i] !='\0'; i++)
	{
		if(str1[i]-str2[i] ==0)
		{
			flag =1;
			continue;
	
		}
		else if( (str1[i]-str2[i])<0)
		{
			printf("string1 is lesser than string2\n");
			break;
		}
		else
		{
			printf("string1 is bigger than string2\n");
			break;
		}
	}
	if(flag ==1)
	{
		printf("both strings are equal\n");
	}
}
