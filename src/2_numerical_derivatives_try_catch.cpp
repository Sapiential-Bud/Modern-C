//
// Created by WinterRain_Bud on 5/11/2025.
//
#include <iostream>
#include <stdexcept>

int main() {
    try {
        int x = 5;
        if (x >= 3) {
            throw std::runtime_error("x is too big!");
        }
    } catch (const std::exception& ex) {
        std::cerr << "Caught exception: " << ex.what() << std::endl;
    }

    std::cout << "Main continues..." << std::endl;
    return 0;
}
