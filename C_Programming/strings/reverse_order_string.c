//268.Write a C program to reverse order of words in a given string.

#include <stdio.h>
int main() 
{
    	char str[10], word[20][50];
    	int i = 0, j = 0, k = 0, wc = 0;
    	printf("Enter any string...\n");
    	fgets(str,sizeof(str),stdin);
    	
	while(str[i] != '\0') 
	{
        	if(str[i] != ' ') 
		{
            		word[wc][j] = str[i];
            		j++;
        	}
	
        	else 
		{
            		word[wc][j] = '\0';
            		wc++;
            		j = 0;
		}
		i++;
    	}
    	word[wc][j] = '\0';
    	printf("Reversed words...\n");
    	for(i = wc; i >= 0; i--) 
	{
        	printf("%s ", word[i]);
    	}
    	printf("\n");
}

