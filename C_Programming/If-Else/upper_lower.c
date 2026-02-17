//Character is uppercase or lowercase
#include <stdio.h>
void main() 
{
    char ch;
    printf("Enter a character:\n");
    scanf(" %c", &ch);
    if (ch >= 'A' && ch <= 'Z')
    {	
        printf("Uppercase Alphabet\n");
    }
    else if (ch >= 'a' && ch <= 'z')
    {
        printf("Lowercase Alphabet\n");
    }
    else
    {
        printf("Not an alphabet\n");
    }
}
