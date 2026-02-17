#include <stdio.h>
#include <string.h>

void main()
{
    int i, n, flag = 0;
    char str[100];

    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);   // Read full line

    n = strlen(str);

    // Remove newline if present
    if (str[n - 1] == '\n')
        str[n - 1] = '\0';

    n = strlen(str); // Update length after removing newline

    for (i = 0; i < n / 2; i++)
    {
        if (str[i] != str[n - i - 1])
        {
            flag = 1;
            break;
        }
    }

    if (flag)
        printf("It is NOT a palindrome\n");
    else
        printf("It is a palindrome\n");
}

