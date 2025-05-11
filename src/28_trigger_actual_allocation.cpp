//
// Created by WinterRain_Bud on 5/12/2025.
//
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <thread>
#include <chrono>



int main() {
    size_t size = 64LL * 1024 * 1024 * 1024;  // 64 GB
    int* big = (int*)malloc(size);

    if (!big) {
        std::cout << "Allocation failed!\n";
    } else {
        std::cout << "malloc() success, now writing to memory...\n";

        // Touch every 1 MB page to force physical allocation
        size_t step = 1024 * 1024;
        for (size_t i = 0; i < size; i += step) {
            big[i / sizeof(int)] = 1;  // write to force page allocation
        }

        std::cout << "Memory written.\n";
    }
    std::this_thread::sleep_for(std::chrono::seconds(10));
    free(big);
    return 0;
}
