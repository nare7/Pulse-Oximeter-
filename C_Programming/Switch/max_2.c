//Maximum between two numbers

#include <stdio.h>
void main() 
{
    int a, b;
    printf("Enter any two numbers:\n");
    scanf("%d%d", &a, &b);

    switch(a > b) 
	{
        	case 1: 
			printf("Maximum = %d\n", a); 
			break;
        	case 0: 
			printf("Maximum = %d\n", b); 
			break;
    	}
}
