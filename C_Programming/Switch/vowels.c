//Alphabet is vowel or consonant

#include <stdio.h>
void main() 
{
    char ch;
    printf("Enter any alphabet:\n");
    scanf(" %c", &ch);

    switch(ch) 
	{
        	case 'a': case 'e': case 'i': case 'o': case 'u':
        	case 'A': case 'E': case 'I': case 'O': case 'U':
            		printf("%c is a Vowel\n",ch); 
			break;
        	default:
            		printf("Consonant\n");
    	}
}
    
