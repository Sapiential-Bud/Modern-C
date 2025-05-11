//
// Created by WinterRain_Bud on 5/12/2025.
//

#include <iostream>
#include <exception>

int counter = 0;

// void test_stack_depth() {
//     int local_array[1024]; // 4 KB stack usage
//     counter++;
//     test_stack_depth();
// }

void test_stack_depth(int depth) {
    int local[256];  // ~1 KB stack usage
    std::cout << "Depth: " << depth << ", &local = " << &local << "\n";
    test_stack_depth(depth + 1);
}


int main() {
    try {
        test_stack_depth(1);
    } catch (...) {
        std::cout << "Caught exception (unlikely on stack overflow)\n";
    }

    std::cout << "Max recursion depth before crash: " << counter << "\n";
    return 0;
}
