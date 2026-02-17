//261.Write a C program to toggle case of each character of a string.

#include <stdio.h>

void main() 
{
    char str[100];
    int i = 0;
    printf("Enter string: \n");
    fgets(str,sizeof(str),stdin);
    while(str[i] != '\0') {
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
        else if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
        i++;
    }
    printf("Toggled case of each char of the string: %s\n", str);
}
