// 275. Find highest frequency character
#include <stdio.h>

void main() 
{
    	char str[100];
    	int i = 0, j, freq[256] = {0}, min = 999;
    	char minChar;

    	printf("Enter any string....\n");
    	fgets(str,sizeof(str),stdin);
    	for(i=0;str[i] != '\0';i++) 
	{
        	freq[str[i]]++;
	}
        //i++;
    
    	for(i = 0; i < 256; i++) 
	{
        	if(freq[i] > 0 && freq[i]<min) 
		{
            		min = freq[i];
            		minChar = i;
       		}
    	}
    	printf("lowest frequency character: %c (%d times)\n", minChar, min);
}
