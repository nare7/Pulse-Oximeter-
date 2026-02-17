#include <stdio.h>

void main() 
{
	unsigned int num = 0x12345678; 
 // Test value
    	unsigned char *ptr = (unsigned char*)&num;  // Pointer to first byte of num

    	printf("Memory Representation: ");
    	for (int i = 0; i < sizeof(num); i++)
	{
        	printf("%02x ", ptr[i]);
	}
    	printf("\n");

    	if (*ptr == 0x78)
	{
        	printf("System is Little Endian\n");
	}
    	else
	{
        	printf("System is Big Endian\n");
	}

}
