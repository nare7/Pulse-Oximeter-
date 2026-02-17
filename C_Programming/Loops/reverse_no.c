//65. Write a C program to reverse any number.

#include<stdio.h>
void main()
{
	int num,digit,rev_no=0,org_num;
	printf("Enter any number...\n");
	scanf("%d",&num);
	org_num = num;
	while(num>0)
	{
		digit = num % 10;
		rev_no =rev_no * 10 +  digit;
		num = num/10;
	}
	printf("Orginal_no : %d\n,Reverse Number : %d\n",org_num,rev_no);
}
