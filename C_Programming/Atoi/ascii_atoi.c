#include <stdio.h>

int asciiStringToInt(char str[]) 
{
	int i=0,res=0,sign = 1;

	if (str[i] == '-') 
	{
        sign = -1;
        i++;
    	}
	//int i = 0, res = 0;

    	while (str[i] != '\0')
	{
        	int digit = (int)str[i] - 48; // '0' in ASCII = 48
        	res = res * 10 + digit;
        	i++;
    	}

    return res * sign ;
}

void main() 
{
	char s[] = "--5678";

   	printf("integer number  = %d\n", asciiStringToInt(s));
}

