//Character is alphabet or not
#include <stdio.h>
void main() 
{
    char ch;
    printf("Enter a character:\n");
    scanf(" %c", &ch);
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
    {
        printf("Alphabet\n");
    }
    else
    {
        printf("Not an alphabet\n");
    }
}
