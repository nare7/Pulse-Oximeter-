#include<stdio.h>
void main(int argc,char* argv[])

{
//	int argv;
	printf("argc = %d",argc);
	for(int i=0;i<argc;i++)
	{
		printf("argc[%d] = %s\n",i,argv[i]);
	}
}
	
