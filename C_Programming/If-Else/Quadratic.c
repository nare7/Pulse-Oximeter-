#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main()
{
	int a,b,c,d;
	float root1,root2,real,img;

	printf("Enter the Coefficients of quadratic equation\n");
	scanf("%d%d%d", &a, &b, &c);

	//d = (b*b) - (4*a*c);
	if( (a==0) && (b==0) && (c==0) )
	{
		printf("Roots Can't be determined\n");
  		exit(0);
	}


	d = (b*b)-(4*a*c);
	if(d==0)
	{
		printf("Roots are Real And Equal:\n");
		root1=(-b)/(2.0*a);
		root2=root1;
		printf("root1:%.2f\nroot2:%.2f\n",(float)root1,(float)root2);
	}
	else if(d>0)
	{
		printf("Roots are Real And Different:\n");
		root1=(-b + sqrt(d))/2.0*a;
		root2=(-b - sqrt(d))/2.0*a;
		printf("root:%.2f\nroot2:%.2f\n",(float)root1,(float)root2);
	}
	else
	{	
		//d = -d;
		printf("Roots are Real And Imaginary:\n");
		real =(float)((-b)/(2.0*a));
		img=(float)sqrt((-1)*d)/2.0*a;
		printf("root1:%.2f+j%.2lf\n",real,img);
		printf("root2:%.2f-j%.2lf\n",real,img);
	}
}

