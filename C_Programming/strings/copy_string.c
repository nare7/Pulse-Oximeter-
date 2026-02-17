#include <stdio.h>
#include <string.h>

void main()
{
	
	int i;
	char str1[100]={"sai"};
	char str2[100]={"srinivas"};
	
	//for(i=0; str2[i] !='\0'; i++)
	//{
		//count++;
	//}
	for(i=0; str2[i] !='\0'; i++)
	{
		str1[i]= str2[i];
	}
	printf("%s\n", str1);

}
