#include<stdio.h>
int my_atoi(char[]);
int my_atoi(char str[])
{
	int i=0,n=0;
	while(str[i] != '\0')
	{
		if (str[i] >='0' && str[i] <= '9')
		{
			n = n*10 + str[i] - '0';
		}
		else
		{
			break;
		}
		i++;
	}
	return n;
}
	
	
void main()
{
	char str[] = "1234s4";
	int num;
	num = my_atoi(str);
	 printf("%s string integer converted to %d interger\n",str,num);
}
	
