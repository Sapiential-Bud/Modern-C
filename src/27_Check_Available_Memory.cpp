//
// Created by WinterRain_Bud on 5/12/2025.
//
#include <windows.h>
#include <iostream>

int main() {
    MEMORYSTATUSEX mem = { sizeof(mem) };
    GlobalMemoryStatusEx(&mem);

    int* big = (int*)malloc(64LL * 1024 * 1024 * 1024);  // 64 GB
    if (!big) std::cout << "Allocation failed!\n";
    else      std::cout << "Success!\n";


    std::cout << "Total Phys Memory: " << mem.ullTotalPhys / (1024 * 1024 * 1024) << " GB\n";
    std::cout << "Avail Phys Memory: " << mem.ullAvailPhys / (1024 * 1024 * 1204) << " GB\n";
    std::cout << "Virtual Memory:    " << mem.ullTotalVirtual / (1024 * 1024 * 1204) << " GB\n";
    std::cout << "Avail Virtual:     " << mem.ullAvailVirtual / (1024 * 1024 * 1204) << " GB\n";



    return 0;
}
