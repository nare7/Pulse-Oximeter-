#include<stdio.h>
#include<string.h>

void main()
{
	int n,i;
	printf("Enter any size of a string...\n");
	scanf("%d",&n);
	
	char str1[n],str2[n];
	
	printf("Enter first string...\n");
	scanf("%s",&str1[n]);
	
	for(i=0;str1 != '\0';i++)
	{
		str2[i] = str1[i];
	}
	for(i=0;str2 != '\0';i++)
	{
		printf("%s",str2[i]);
	}

	
//	puts(str2);
}
