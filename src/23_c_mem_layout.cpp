//
// Created by WinterRain_Bud on 5/12/2025.
//
#include <iostream>
#include <cstdlib>

void greet(int x) {
    std::cout << "Hello: " << x << std::endl;
}

int main() {
    // Stack
    int stack_var = 42;

    // Heap
    int* heap_var = (int*)malloc(sizeof(int));
    *heap_var = 99;

    // Function pointer (also on the stack)
    void (*f)(int) = greet;

    // Print addresses
    std::cout << "=== Memory Regions ===\n";

    std::cout << "stack_var:       " << &stack_var << "   (stack)\n";
    std::cout << "heap_var:        " << heap_var     << "   (heap)\n";
    std::cout << "&heap_var:       " << &heap_var    << "   (stack-pointer to heap)\n";

    std::cout << "f (func ptr):    " << (void*)f      << "   (code-function address)\n";
    std::cout << "&f:              " << &f            << "   (stack-pointer variable)\n";

    std::cout << "greet:           " << (void*)greet  << "   (code-function address)\n";
    std::cout << "&greet:          " << (void*)&greet << "   (same as greet-code)\n";

    // Clean up
    free(heap_var);

    return 0;
}
