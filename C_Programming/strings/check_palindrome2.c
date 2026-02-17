#include <stdio.h>
#include <string.h>

void main()
{
	int i,n, flag =0;
	char str[100];
	printf("enter the string\n");
	//scanf("%s", str);
	char ch =fgets(str,sizeof(str),stdin);

	n= strlen(ch);
	
	for(i=0; i<n/2; i++)
	{
		if(ch[i] != ch[n-i-1])
		{
			flag =1;
			break;
		}
	}
	if(flag)
	{
		printf("it is not palindrome\n");
	}
	else
	{
		printf("it is  palindrome\n");
	}
}
