#include <stdio.h>

int recursiveStringToInt(char *str, int len) 
{
    if (len == 0)
        return 0;

    int digit = str[len - 1] - '0';
    return recursiveStringToInt(str, len - 1) * 10 + digit;
}

void main() 
{
	char s[] = "7890";
    	int len = 4;
   	printf("Result = %d\n", recursiveStringToInt(s, len));
    
}

