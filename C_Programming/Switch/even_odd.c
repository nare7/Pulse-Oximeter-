//Even or Odd

#include <stdio.h>
void main() 
{
    int num;
    printf("Enter any number:\n");
    scanf("%d", &num);

    switch(num % 2) 
	{
        	case 0: 
			printf("%d is a Even number\n",num); 
			break;
        	case 1: 
			printf("%d is a Odd number\n",num); 
			break;
    	}

}
