#include <stdio.h>
#include <string.h>

void main()
{
	int count=0;
	char i,str[100], str2[100];
	printf("Enter the string\n");
	scanf("%s", str);
	for(i=0; str[i] !='\0'; i++)
	{
		count++;
	}
	printf("count is %d\n",count);

}
