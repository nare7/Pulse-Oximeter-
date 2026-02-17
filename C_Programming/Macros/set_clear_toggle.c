#include<stdio.h>
#define set_a_bit(num,pos) (num | (1<<pos))
#define clear_a_bit(num,pos) (num & (~(1<<pos)))
#define toggle_a_bit(num,pos) (num ^ (1<<pos))

void main()
{
	int num,pos,set,clear,toggle;
	printf("Enter any number .....\n");
	scanf("%x",&num);
	printf("Enter any position....\n");
	scanf("%d",&pos);
	set = set_a_bit(num,pos);
	clear = clear_a_bit(num,pos);
	toggle = toggle_a_bit(num,pos);
	printf("Set A Bit :- Decimal:%d,Hex:%x\n Clear A Bit :- Decimal:%d,Hex:%x\n Toggle A Bit :- Decimal:%d,Hex:%x\n",set,set,clear,clear,toggle,toggle);
}
