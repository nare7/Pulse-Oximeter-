//270.Write a C program to find first occurrence of a character in a given string.
#include <stdio.h>

void main() 
{
    	char str[100], ch;
    	int i = 0, pos = -1;

    	printf("Enter any string...\n");
    	fgets(str,sizeof(str),stdin);

    	printf("Enter any character...\n");
    	scanf("%c", &ch);

	while(str[i] != '\0') 
	{
        	if(str[i] == ch) 
		{
            		pos = i;
            		break;

	        }
        	i++;
    	}
    	if(pos != -1)
	{
        	printf("First occurrence at position...%d\n", pos);
	}
    	else
	{
        	printf("Character not found...\n");
	}
    
}
