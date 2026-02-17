//Divisible by 5 and 11
#include <stdio.h>
void main() 
{
    int num;
    printf("Enter a number:\n");
    scanf("%d", &num);
    if (num % 5 == 0 && num % 11 == 0)
    {
        printf("%d : Divisible by 5 and 11\n",num);
    }
    else
    {
        printf("%d : Not divisible by 5 and 11\n",num);
    }
}
