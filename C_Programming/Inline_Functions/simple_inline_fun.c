
#include <stdio.h>

static inline int square(int x) {
    return x * x;
}

int main() {
    int k=square(5);
    printf("Square of 5 = %d\n", k);
    return 0;
}

