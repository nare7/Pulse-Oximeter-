//276.Write a C program to count frequency of each character in a string.

#include <stdio.h>

void main() 
{
    	char str[100];
    	int i = 0, j, freq[256] = {0}, max = 0,count=0;
    	char maxChar;

    	printf("Enter any string....\n");
    	fgets(str,sizeof(str),stdin);
    	for(i=0;str[i] != '\0';i++) 
	{
        	freq[str[i]]++;
	//	printf("%d\n",(int)freq[str[i]]);
	}
	
        //i++;
    
    	for(i = 0; i < 256; i++) 
	{
        	if(freq[i] > 0) 
		{
            		printf("count freq of char...%c index %d\n",i,freq[i]);
       		}
    	}
}

