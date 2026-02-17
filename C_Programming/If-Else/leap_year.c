//Leap year or not
#include <stdio.h>
void main() 
{
    int year;
    printf("Enter any year:\n");
    scanf("%d", &year);
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
    {
        printf("%d : is a Leap year\n",year);
    }
    else
    {
        printf("%d : is not a leap year\n",year);
    }
}
