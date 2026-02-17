#include <stdio.h>

void main()
{
	int count=0;
	char i, str[10];
	printf("enter the string\n");
	scanf("%s", str);
	
	for(i=0; str[i] !='\0'; i++)
	{
		printf("%c", str[i]);
		if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
		str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
		{
			count++;
		}
	}
	printf("\nno of vowels in the string is %d", count);
}
