//
// Created by WinterRain_Bud on 5/12/2025.
//
#include <windows.h>
#include <iostream>

void recurse(int depth) {
    int x = depth;
    std::cout << "Depth " << depth << ": &x = " << &x << "\n";
    if (depth < 10) recurse(depth + 1);
}

int main() {
    int local_var;
    MEMORY_BASIC_INFORMATION mbi;
    VirtualQuery(&local_var, &mbi, sizeof(mbi));

    std::cout << "Stack base (high): " << mbi.AllocationBase << "\n";
    std::cout << "Current address  : " << &local_var << "\n";
    std::cout << "Stack size       : " << mbi.RegionSize << " bytes\n";

    std::cout << "Estimated stack used: "
              << ((uintptr_t)&local_var - (uintptr_t)mbi.AllocationBase)
              << " bytes\n";


    recurse(1);
    return 0;
}
