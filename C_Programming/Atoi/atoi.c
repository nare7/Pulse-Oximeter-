#include<stdio.h>
#include<stdlib.h>
void main()
{
	int num1,num2,num3,num4;
	char str1[]="2002", str2[]="  2002",str3[]="12a12",str4[]="hello";
	num1=atoi(str1);
	num2=atoi(str2);
	num3=atoi(str3);
	num4=atoi(str4);
	printf("%s string integer converted to %d interger\n",str1,num1);
	 printf("%s string integer converted to %d interger\n",str2,num2);
	 printf("%s string integer converted to %d interger\n",str3,num3);
	 printf("%s string integer converted to %d interger\n",str4,num4);
}
