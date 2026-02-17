//281.Write a C program to replace first occurrence of a character with another i a string

#include<stdio.h>

void main()
{
	char str[10],first_occ,replace;
	
	printf("Enter any string...\n");
	fgets(str,sizeof(str),stdin);
	
	printf("Enter first occurance....\n");
	scanf("%c",&first_occ);
	
	printf("Enter replace char....\n");
	scanf(" %c",&replace);

	for(int i=0;str[i] != '\0';i++)
	{
		if(str[i]==first_occ)
		{
			str[i]=replace;
		}
		//puts(str);
		printf("%c",str[i]);
	}
	//puts(str);
}

	
