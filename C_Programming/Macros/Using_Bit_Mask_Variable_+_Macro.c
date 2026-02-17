#include <stdio.h>

#define BIT_MASK(pos)   (1 << (pos))
#define TOGGLE(num, mask)  ((num) ^ (mask))

void main() 
{
	int num = 10,pos=2;       // 00001010
    	int mask = BIT_MASK(pos);  // 00001000

    	printf("Before: %d\n", num);
    	num = TOGGLE(num, mask);
    	printf("After : %d\n", num);
}

