//
// Created by WinterRain_Bud on 5/11/2025.
//
#include <iostream>
#include <cstdlib>    // for malloc, free

void printInt(int x) {
    std::cout << "Function called with: " << x << std::endl;
}

struct Point {
    int x;
    int y;
};

int main() {
    // 1. Basic pointer
    int a = 10;
    int* p = &a;
    std::cout << "1. a = " << a << ", *p = " << *p << std::endl;

    // 2. Null pointer (don't dereference it)
    int* nullPtr = nullptr;
    // std::cout << *nullPtr; // 💥 Would crash

    // 3. Dangling pointer (use-after-free)
    int* d = (int*)malloc(sizeof(int));
    *d = 42;
    std::cout << "2. Before free: *d = " << *d << std::endl;
    free(d);
    // std::cout << *d; // 💥 Use-after-free bug (undefined behavior)

    // 4. Pointer arithmetic
    int arr[3] = {11, 22, 33};
    int* parr = arr;
    std::cout << "3. Pointer arithmetic: " << *parr << " " << *(parr + 1) << std::endl;

    // 5. Arrays vs pointers
    std::cout << "4. arr[2] = " << arr[2] << ", *(arr + 2) = " << *(arr + 2) << std::endl;

    // 6. Double pointer
    int x = 99;
    int* px = &x;
    int** ppx = &px;
    std::cout << "5. Double pointer: **ppx = " << **ppx << std::endl;

    // 7. Struct pointer
    Point pt = {7, 8};
    Point* ppt = &pt;
    std::cout << "6. Struct pointer: ppt->x = " << ppt->x << ", ppt->y = " << ppt->y << std::endl;

    // 8. Function pointer
    void (*fp)(int) = printInt;
    fp(123);  // same as printInt(123)

    return 0;
}
