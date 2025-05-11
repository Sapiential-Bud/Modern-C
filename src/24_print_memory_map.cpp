//
// Created by WinterRain_Bud on 5/12/2025.
//
#include <windows.h>
#include <iostream>

void print_memory_map() {
    MEMORY_BASIC_INFORMATION mbi;
    unsigned char* addr = nullptr;

    std::cout << "=== Virtual Memory Map ===\n";

    while (VirtualQuery(addr, &mbi, sizeof(mbi))) {
        std::cout << "Base: " << mbi.BaseAddress
                  << " | Size: " << mbi.RegionSize
                  << " | Type: ";

        if (mbi.Type == MEM_IMAGE) std::cout << "IMAGE";
        else if (mbi.Type == MEM_MAPPED) std::cout << "MAPPED";
        else if (mbi.Type == MEM_PRIVATE) std::cout << "PRIVATE";
        else std::cout << "UNKNOWN";

        std::cout << "\n";

        addr += mbi.RegionSize;
    }
}

int main() {
    print_memory_map();
    return 0;
}
