#include<stdio.h>
void main()
{
	float  centimeter,meter,km;
	printf("Enter the centimeter : ");
	scanf("%f",&centimeter);
	meter = centimeter / 100;
	km = centimeter / 100000;
	printf("meter : %d\n",(int)meter);
	printf("Kilo Meter : %d\n",(int)km);
	printf("Meter : %f\n",meter);
	printf("Kilo Meter : %f\n",km);
}
