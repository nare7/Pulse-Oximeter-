#include <stdio.h>
#include <stdlib.h> // For malloc and free

// Global initialized variable (Data Segment)
int global_initialized_var = 10;

// Global uninitialized variable (BSS Segment - part of Data Segment)
int global_uninitialized_var;

// Function to simulate code segment location (Text Segment)
void func_in_code_segment() {
    printf("Address of func_in_code_segment: %p\n", (void*)func_in_code_segment);
}

int main() {
    // Local variable (Stack Segment)
    int local_var = 20;

    // Dynamically allocated memory (Heap Segment)
    int *heap_var = (int *)malloc(sizeof(int));
    if (heap_var == NULL) {
        perror("malloc failed");
        return 1;
    }
    *heap_var = 30;

    printf("--- Memory Segment Locations (Relative) ---\n");

    // Code Segment (Text Segment)
    func_in_code_segment();

    // Data Segment (Initialized)
    printf("Address of global_initialized_var: %p\n", (void*)&global_initialized_var);

    // Data Segment (Uninitialized/BSS)
    printf("Address of global_uninitialized_var: %p\n", (void*)&global_uninitialized_var);

    // Heap Segment
    printf("Address of heap_var (pointer): %p\n", (void*)&heap_var); // Address of the pointer itself
    printf("Address of allocated memory on heap: %p\n", (void*)heap_var);

    // Stack Segment
    printf("Address of local_var: %p\n", (void*)&local_var);

    // Clean up heap memory
    free(heap_var);

    printf("\n--- Observations ---\n");
    printf("Addresses generally follow a pattern (e.g., Code, Data, Heap, Stack).\n");
    printf("The exact addresses and sizes are managed by the OS and are not directly accessible in a portable C way.\n");
    printf("Tools like 'size' (on Linux) or debuggers can provide more detailed segment information for executables.\n");

    return 0;
}
