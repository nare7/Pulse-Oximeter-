#include<stdio.h>
void bitwise(int number)
{
	int pos1,pos2,pos3,set_bit,clear_bit,toggle_bit;
	//printf("Enter the any three hexa numbers...\n");
//	scanf("%x%x%x",&num1,&num2,&num3);
	printf("Enter the positions...\n");
	scanf("%d%d%d",&pos1,&pos2,&pos3);
	printf("Set A Bit....\n");
	set_bit = number | (0x1 << pos1);
	printf("%x - Hexa , %d - Decimal , %b - Binary\n",set_bit,set_bit,set_bit);

	printf("Clear A Bit....\n");
	clear_bit = number | (0x1 << pos2);
	printf("%x - Hexa , %d - Decimal, %b - Binary\n",clear_bit,clear_bit,clear_bit);

	printf("Toggle A Bit...\n");
	toggle_bit = number | (0x1 << pos3);
	printf("%x - Hexa , %d - Decimal, %b - Binary\n",toggle_bit,toggle_bit,toggle_bit);
}


