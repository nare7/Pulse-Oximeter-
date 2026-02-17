//check palindrome in strings
#include <stdio.h>
#include <string.h>

void main()
{	
	int i, n, temp, flag=1;
	//printf("enter the length of the string\n");
	//scanf("%d", &n);

	char str1[100], str2[100];
	printf("enter the characters of string\n");
	scanf("%s", str1);
	//scanf("%s", str1);
	/*for(i=0; i<n; i++)
	{
		scanf("%c", &str1[i]);
	}
	*/
	
	for(i=0; str1[i] !='\0'; i++)
	{
		str2[i]= str1[i];
	}
	
	
	 //strcpy(str2, str1);

    // Find length
     n = strlen(str1);
	
	for(i=0; i<n/2; i++)
	{
		temp = str1[i];
		str1[i] = str1[n - i - 1];
		str1[n - i - 1] = temp;
	}
	

	printf("reversed string is\n");
	//for(i=0; i<n; i++)
	//{
		printf("%s\n",str1);
	//}

	
	for(i=0; i<n; i++)
	{
		if(str1[i] != str2[i])
		{
			flag =0;
			break;
		}

	}
	if(flag)
	{
		printf("it is palindrome\n");
	}
	else
	{
		printf("it is not palindrome\n");
	}
}

