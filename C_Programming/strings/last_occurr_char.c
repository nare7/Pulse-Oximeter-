//278.Write a C program to remove last occurrence of a character from string

#include<stdio.h>
#include<string.h>

void main()
{
	char str[10],ch,i, last;
	
	printf("Enter the string....\n");
	fgets(str,sizeof(str),stdin);
	
	printf("Enter any char...\n");
	scanf(" %c",&ch);

	int n= strlen(str);
	
	for(i=0; str[i] != '\0'; i++)
	{
		if(str[i] == ch)
		{
			last = i;
		}
	}
	for(i=0;str[i] != '\0';i++)
	{
		if(last == i)
		continue;
		printf("%c",str[i]);
	}
}
