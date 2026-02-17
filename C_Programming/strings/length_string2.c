//find the length of the string method 2

#include <stdio.h>
#include <string.h>

void main()
{
	int i=0;
	char str[50];
	printf("enter the string\n");
	scanf("%s", str);
	
	while(str[i] != '\0')
	{
		i++;
	}
	
	printf("length is %d ", i);
}
