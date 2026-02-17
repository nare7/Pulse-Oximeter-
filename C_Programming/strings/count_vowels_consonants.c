//264.Write a C program to count total number of vowels and consonants in a string.
#include <stdio.h>
void main() 
{
	char str[10];
    	int i = 0, vowel = 0, consonant = 0;
   	printf("Enter any string....\n");
    	fgets(str,sizeof(str),stdin);
   	while(str[i] != '\0') 
	{
        	if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) 
		{
            		if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||
               			str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U')
			{
                		vowel++;
			}
            		else
			{
                		consonant++;
			}
		}
		i++;
        }
       // i++;
    	printf("Total Number of Vowels are...%d\n", vowel);

    	printf("Total Number of Consonants are...%d\n", consonant);
   
}

