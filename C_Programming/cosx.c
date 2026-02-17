#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

void main()
{
    int i, n;
    float x, radians, term, cosval, cosx, den;

    
    printf("Enter how many terms you want in the series: ");
    scanf("%d", &n);
    printf("Enter the angle in degrees: ");
    scanf("%f", &x);

    radians = (PI * x) / 180.0;

    
    term = 1;
    cosval = term;
    i = 1;

    
    do
    {
        den = (2 * i - 1) * (2 * i);               
        term = (-term * radians * radians) / den; 
        cosval += term;                           
        i++;
    } while (i <= n);

    cosx = cos(radians);
    printf("\n%f : Calculated Value ....\n", cosval);
    printf("%f : Library Value ......\n", cosx);
}
