//Simple Calculator

#include <stdio.h>
void main() 
{
    char op;
    int a, b;
    float division;
    printf("Enter an operator (+, -, *, /):\n");
    scanf(" %c",&op);
    printf("Enter any two numbers:\n");
    scanf("%d %d", &a, &b);
    switch(op) 
	{
        	case '+': 
			printf("%d + %d = %d\n", a, b, a+b); 
			break;
        	case '-': 
			printf("%d - %d = %d\n", a, b, a-b); 
			break;
       		case '*': 
			printf("%d * %d = %d\n", a, b, a*b); 
			break;
        	case '/': 
			printf("%f div %f = %f\n",(float)a,(float)b,division);
			break;
		case '%':
			printf("%d mod %d = %d\n",a,b,a%b);
			break;
        	default: 
            		printf("Invalid operator!\n");
    	}
}
