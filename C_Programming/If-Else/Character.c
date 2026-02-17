//Character is alphabet, digit or special character
#include <stdio.h>
void main()
{
    char ch;
    printf("Enter a character:\n");
    scanf(" %c", &ch);
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
    {
        printf("%c : is a Alphabet\n",ch);
    }
    else if (ch >= '0' && ch <= '9')
    {
        printf("%d : is a Digit\n",ch);
    }
    else
    {
        printf("%c : is a Special Character\n",ch);
    }
}
