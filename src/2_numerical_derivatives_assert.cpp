//
// Created by WinterRain_Bud on 5/11/2025.
//
#include <iostream>
#include <stdexcept>
#include <assert.h>

int main() {
    int x = 5;
    assert(x > 0);   // OK
    assert(x < 3);   // Fails here
    std::cout << "Main continues..." << std::endl;
    return 0;
}
