//
// Created by WinterRain_Bud on 5/14/2025.
//
#include <windows.h>
#include <stdio.h>

int main() {
    FARPROC addr = GetProcAddress(GetModuleHandleA("kernel32.dll"), "Sleep");
    printf("Address of Sleep(): %p\n", addr);
    return 0;
}
