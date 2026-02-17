#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void quadratic(int x,int y,int z)
{
	
	float root1,root2,real,img,d;

	printf("Enter the Coefficients of quadratic equation\n");
	scanf("%d%d%d", &x, &y, &z);

	//d = (b*b) - (4*a*c);
	if( (y==0) && (x==0) && (z==0) )
	{
		printf("Roots Can't be determined\n");
  		exit(0);
	}


	d = (y*y)-(4*x*z);
	if(d==0)
	{
		printf("Roots are Real And Equal:\n");
		root1=(-y)/(2.0*x);
		root2=root1;
		printf("root1:%.2f\nroot2:%.2f\n",(float)root1,(float)root2);
	}
	else if(d>0)
	{
		printf("Roots are Real And Different:\n");
		root1=(-y + sqrt(d))/2.0*x;
		root2=(-y - sqrt(d))/2.0*x;
		printf("root:%.2f\nroot2:%.2f\n",(float)root1,(float)root2);
	}
	else
	{	
		//d = -d;
		printf("Roots are Real And Imaginary:\n");
		real =(float)((-y)/(2.0*x));
		img=(float)sqrt((-1)*d)/2.0*x;
		printf("root1:%.2f+j%.2lf\n",real,img);
		printf("root2:%.2f-j%.2lf\n",real,img);
	}
}
