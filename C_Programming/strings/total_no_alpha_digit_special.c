//263.Write a C program to find total number of alphabets, digits or special character in a string.
#include <stdio.h>
void main() 
{

    char str[10];

    int i = 0, alpha = 0, digit = 0, special = 0;

    printf("Enter any string...\n");
    fgets(str,sizeof(str),stdin);

    while(str[i] != '\0') 
	{
        	if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		{
			alpha++;
		}

        	else if(str[i] >= '0' && str[i] <= '9')
		{
	
            		digit++;
		}
        	else if(str[i] != ' ')
		{
			special++;
		}

        	i++;
    }
    printf("Total No of Alphabets are....%d\n", alpha);

    printf("Total No of Digits are....%d\n", digit);

    printf("Total No of Special characters are....%d\n", special);
}

