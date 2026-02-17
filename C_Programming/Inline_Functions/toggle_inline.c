#include <stdio.h>

// Inline function to toggle a bit
static inline int toggle_bit(int num, int pos) 
{
    return num ^ (1 << pos);
}

void main() 
{
    int num = 10;  // Binary: 00001010
    int pos = 3;

    printf("Before toggle: %d\n", num);
    num = toggle_bit(num, pos);
    printf("After toggle : %d\n", num);

}

