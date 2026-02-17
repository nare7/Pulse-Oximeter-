#include<stdio.h>
void main()
{
	float p,t,r,simple_interest; // p-principal amount r- rate of interest t - Time period(years)
	printf("Enter The Principal amount,Rate of Interest,Time Period : \n");
	scanf("%f%f%f",&p,&t,&r);
	simple_interest = (p * t * r) / 100;
	printf("Simple Interest : %f\n",simple_interest);
}
				   
