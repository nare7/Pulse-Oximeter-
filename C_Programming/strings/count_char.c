//Write a C program to find total number of alphabets, digits or special character in a string
#include <stdio.h>
#include <string.h>
void main()
{
	int i, count_alph=0,count_digits=0, count_splchar=0;
	char str[100];
	printf("enter the string1\n");
	//scanf("%s", str);
	
	fgets(str, sizeof(str), stdin);
	
	for(i=0; str[i] !='\0'; i++)
	{
		if( (str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z') )
		{
			count_alph++;
		}
		else if(str[i]>='0' && str[i] <='9')
		{
			count_digits++;
		}
		else
		{
			count_splchar++;
		}
		
	}
	printf("no of alphabets are%d\n", count_alph);
	printf("no of digits are%d\n", count_digits);
	printf("no of alphabets are%d\n", count_splchar);

}
