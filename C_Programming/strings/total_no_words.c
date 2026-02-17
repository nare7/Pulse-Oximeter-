//265.Write a C program to count total number of words in a string.

#include <stdio.h>

void main() 
{
	char str[10];
    	int i = 0, words = 0;

    	printf("Enter any string....\n");
    	fgets(str,sizeof(str),stdin);

    	while(str[i] != '\0') 
	{
        	if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n') 
		{
            		words++;
        	}
		i++;
	}
        
       printf("Total number of words in a String..%d\n", words + 1);
}
