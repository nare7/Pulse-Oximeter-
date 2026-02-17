//272.Write a C program to search all occurrences of a character in given string

#include <stdio.h>

void main() 
{
    	char str[10], ch;
    	int i = 0;
    	
	printf("Enter any string...\n");
    	fgets(str,sizeof(str),stdin);
    	
	printf("Enter any  character....\n");
    	getchar();
	scanf("%c", &ch);
    	printf("Occurrences at positions....\n");
   	
	while(str[i] != '\0') 
	{
        	if(str[i] == ch) 
		{
            		printf("%d ", i);
        	}
        	i++;
    	}
    	printf("\n");
    
}
