// 274. Find highest frequency character
#include <stdio.h>

void main() 
{
    	char str[100];
    	int i = 0, j, freq[256] = {0}, max = 0;
    	char maxChar;

    	printf("Enter any string....\n");
    	fgets(str,sizeof(str),stdin);
    	for(i=0;str[i] != '\0';i++) 
	{
        	freq[str[i]]++;
	}
        //i++;
    
    	for(i = 0; i < 256; i++) 
	{
        	if(freq[i] > max) 
		{
            		max = freq[i];
            		maxChar = i;
       		}
    	}
    	printf("Highest frequency character: %c (%d times)\n", maxChar, max);
}
