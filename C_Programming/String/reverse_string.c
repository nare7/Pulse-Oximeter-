#include<stdio.h>
#include<string.h>
//#include<conio.h>


void main()
{
	int ch[100] ;
	
	printf("Enter any string...");
	ch=fgets(ch,sizeof(ch),stdin);
	puts(ch);
}
