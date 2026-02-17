//find the length of the string

#include <stdio.h>
#include <string.h>
void main()
{
	int length;
	char str[50];
	printf("enter the string\n");
	scanf("%s",str);
	length = strlen(str);
	printf("%d\n",length);
}
