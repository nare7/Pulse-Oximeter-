// Roots Of Quadratic Equations

#include<stdio.h>
#include <math.h>
void main() 
{
    int a, b, c;
    float root1, root2,real,img;
    printf("Enter coefficients a, b, c:\n");
    scanf("%d%d%d", &a, &b, &c);

    float d = b*b - 4*a*c;

    switch(d > 0 ? 1 : (d == 0 ? 2 : 3)) 
	{
        	case 1: // Real and distinct
            		root1 = (float)(-b + sqrt(d)) / (2*a);
            		root2 = (float)(-b - sqrt(d)) / (2*a);
            		printf("Roots are real and distinct: %.2f and %.2f\n", root1, root2);
            		break;
        	case 2: // Real and equal
            		root1 = root2 = (float)-b / (2*a);
            		printf("Roots are real and equal: %.2f and %f\n", root1,root2);
            		break;
        	case 3: // Imaginary
			real = (float)(-b) /(2.0*a);
			img = (float)sqrt((-1)*(d))/(2.0*a);
            		printf("Roots are imaginary\n");
			printf("Root1: %f + j%f\n",real,img);
			printf("Root2: %f - j%f\n",real,img);
            	 	break;
    	}
}
