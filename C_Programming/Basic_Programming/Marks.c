#include<stdio.h>
void main()
{
	unsigned int m1,m2,m3,m4,m5,total;
	float avg,percentage;
	printf("Enter the marks :\n");
	scanf("%d%d%d%d%d",&m1,&m2,&m3,&m4,&m5);
	total = m1+m2+m3+m4+m5;
	avg = total/5;
	percentage = (total/500.0)*100;
	printf("Total :%d\n",total);
	printf("Average :%f\n",avg);
	printf("Percentage : %f\n",percentage);
}
