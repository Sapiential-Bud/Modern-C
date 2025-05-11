//
// Created by WinterRain_Bud on 5/11/2025.
//
#include <iostream>

void static_counter() {
    static int count = 0;  // persists between calls
    count++;
    std::cout << "static_counter: " << count << std::endl;
}

void normal_counter() {
    int count = 0;  // resets every time
    count++;
    std::cout << "normal_counter: " << count << std::endl;
}

int main() {
    std::cout << "Calling each function 5 times:\n";

    for (int i = 0; i < 5; ++i) {
        static_counter();
        normal_counter();
        std::cout << "------\n";
    }

    static_counter();
    return 0;
}
