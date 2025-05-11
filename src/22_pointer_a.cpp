//
// Created by WinterRain_Bud on 5/11/2025.
//
#include <iostream>
#include <cstdlib>   // for malloc/free
#include <cstring>   // for memcpy
#include <memory>    // for smart pointers
#include <stdexcept>

// ========== Struct for linked list ==========
struct Node {
    int value;
    Node* next;
};

// ========== Swap using pointer ==========
void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void change_copy(int a) {
    a = 11;  // only changes the copy
    std::cout << "a in change_copy = " << a << "\n";
    std::cout << "&a in change_copy = " << &a << "\n";
}

int* change_copy_return(int a) {
    a = 22;  // only changes the copy
    std::cout << "a in change_copy_return = " << a << "\n";
    std::cout << "&a change_copy_return = " << &a << "\n";
    return &a;
}

void change_poi(int* a) {
    *a = 99;  // modifies the value at the address
}

void change_ref(int& a) {
    a = 55;
}

int* malloca_test(){
    int* p = (int*)malloc(sizeof(int));  // C
    *p = 10;
    std::cout << "*p = " << *p << "\n";
    std::cout << "&p = " << &p << "\n";
    std::cout << "p = " << p << "\n";
    return  p;
}

// ========== Function pointer ==========
void greet(int id) {
    std::cout << "Hello from function " << id << std::endl;
}

// ========== Polymorphism ==========
class Base {
public:
    virtual void speak() { std::cout << "Base speaking\n"; }
};

class Derived : public Base {
public:
    void speak() override { std::cout << "Derived speaking\n"; }
};

// ========== Simulated hardware register ==========
volatile unsigned int FAKE_HARDWARE_PORT = 0;

int main() {
    std::cout << "\n1. Basic pointer\n";
    int x = 10;
    int* px = &x;
    std::cout << "Value: " << *px << "\n";

    std::cout << "\n2. Swap via pointer\n";
    int a = 3, b = 7;
    std::cout << "a = " << &a << ", b = " << &b << "\n";
    swap(&a, &b);
    std::cout << "First Swap"<<"\n";
    std::cout << "a = " << a << ", b = " << b << "\n";
    std::cout << "a = " << &a << ", b = " << &b << "\n";
    int c = a;
    a = b;
    b = c;
    std::cout << "Second Swap"<<"\n";
    std::cout << "a = " << a << ", b = " << b << "\n";
    std::cout << "a = " << &a << ", b = " << &b << "\n";

    std::cout << "x1 test"<<"\n";
    int x1 = 5;
    std::cout << "x1 = " << x1 << "\n";
    std::cout << "x1 = " << &x1 << "\n";
    change_copy(x1);
    std::cout << "x1 = " << x1 << "\n";
    std::cout << "x1 = " << &x1 << "\n";
    change_poi(&x1);
    std::cout << "x1 = " << x1 << "\n";
    std::cout << "x1 = " << &x1 << "\n";
    change_ref(x1);
    std::cout << "x1 = " << x1 << "\n";
    std::cout << "&x1 = " << &x1 << "\n";

    int* x2 = change_copy_return(x1) ;
    //std::cout << "change_copy_return_value = " << *x2 << "\n";
    std::cout << "x2 = " << x2 << "\n";
    std::cout << "&x2 = " << &x2 << "\n";

    int* x3 ;
    x3 =  (int*)0xbebbbff9f0;
    std::cout << "x3 = " << x3 << "\n";
    std::cout << "&x3 = " << &x3 << "\n";

    int* p = (int*)malloc(sizeof(int));  // C
    *p = 10;
    std::cout << "*p = " << *p << "\n";
    std::cout << "&p = " << &p << "\n";
    std::cout << "p = " << p << "\n";
    *p = 11;
    std::cout << "*p = " << *p << "\n";
    std::cout << "&p = " << &p << "\n";
    std::cout << "p = " << p << "\n";

    x2 = p;
    std::cout << "*x2 = " << *x2 << "\n";
    std::cout << "&x2 = " << &x2 << "\n";
    std::cout << "x2 = " << x2 << "\n";
    *x2 = 12;
    std::cout << "*x2 = " << *x2 << "\n";
    std::cout << "&x2 = " << &x2 << "\n";
    std::cout << "x2 = " << x2 << "\n";

    x3 = p;
    std::cout << "*x3 = " << *x3 << "\n";
    std::cout << "&x3 = " << &x3 << "\n";
    std::cout << "x3 = " << x3 << "\n";

    std::cout << "*p = " << *p << "\n";
    std::cout << "&p = " << &p << "\n";
    std::cout << "p = " << p << "\n";

    malloca_test();
    int* x4 = malloca_test();
    std::cout << "x4 = " << x4 << "\n";
    std::cout << "&x4 = " << &x4 << "\n";
    std::cout << "*x4 = " << *x4 << "\n";
    delete p;
    free(x4);


    std::cout << "\n3. Dynamic memory allocation\n";
    int* dyn = (int*)malloc(6 * sizeof(int));
    for (int i = 0; i < 5; i++) dyn[i] = i * 10;
    for (int i = 0; i < 10; i++) std::cout << dyn[i] << " ";
    std::cout << "\n";
    free(dyn);

    std::cout << "\n4. Linked list (Node)\n";
    Node n1 = {1, nullptr};
    Node n2 = {2, nullptr};
    n1.next = &n2;
    std::cout << "n1 -> " << n1.value << ", n1.next -> " << n1.next->value << "\n";

    std::cout << "\n5. Pointer arithmetic\n";
    int arr[] = {100, 200, 300};
    int* pa = arr;
    std::cout << *(pa + 1) << ", " << pa[2] << "\n";

    std::cout << "\n6. Double pointer\n";
    int val = 42;
    int* p1 = &val;
    int** p2 = &p1;
    std::cout << "Double dereference: " << **p2 << "\n";

    std::cout << "\n7. Function pointer\n";
    void (*fptr)(int) = greet;
    std::cout << "fptr = " << (void*)fptr << "\n";
    std::cout << "(void*)&fptr = " << (void*)&fptr << "\n";
    std::cout << "&fptr = " << &fptr << "\n";
    std::cout << "*fptr = " << (void*)*fptr << "\n";
    std::cout << "\n";
    fptr(123);
    std::cout << "fptr = " << (void*)fptr << "\n";
    std::cout << "(void*)&fptr = " << (void*)&fptr << "\n";
    std::cout << "&fptr = " << &fptr << "\n";
    std::cout << "*fptr = " << (void*)*fptr << "\n";
    std::cout << "\n";
    greet(456);
    std::cout << "greet = " << (void*)greet << "\n";
    std::cout << "(void*)&greet = " << (void*)&greet << "\n";
    std::cout << "greet = " << greet << "\n";
    std::cout << "&greet = " << &greet << "\n";
    std::cout << "*greet = " << (void*)*greet << "\n";

    std::cout << "\n";
    std::cout << "\n8. Struct pointer\n";
    Node* pnode = new Node{999, nullptr};
    std::cout << "pnode->value = " << pnode->value << "\n";
    delete pnode;

    std::cout << "\n9. Polymorphism with vtable\n";
    Base* obj = new Derived();
    obj->speak();
    delete obj;

    std::cout << "\n10. Smart pointer\n";
    std::unique_ptr<int> uptr = std::make_unique<int>(55);
    std::cout << "*uptr = " << *uptr << "\n";

    std::cout << "\n11. Simulated hardware pointer access\n";
    volatile unsigned int* port = &FAKE_HARDWARE_PORT;
    *port = 0xDEADBEEF;
    std::cout << "FAKE_HARDWARE_PORT = 0x" << std::hex << *port << "\n";

    std::cout << "\n12. Array of pointers\n";
    //const char* names[] = {"Alice", "Bob", "Charlie"};
    char* names[] = {"Alice", "Bob", "Charlie"};
    std::string str[] = {"Alice", "Bob", "Charlie"};
    for (int i = 0; i < 3; i++) std::cout << names[i] << "\n";
    for (int i = 0; i < 3; i++) std::cout << str[i] << "\n";

    char names_buf[][20] = {"Alice", "Bob", "Charlie"};  // Writable 2D array
    names_buf[0][0] = 'a';  // ✅ OK
    std::cout << names_buf[0] << std::endl;  // "alice"

    char* names2[] = {"Alice", "Bob", "Charlie"};
    try {
        //names2[0][0] = 'a';  // 💥 Undefined behavior, may crash
    }catch (const std::exception& ex) {
        std::cerr << "Caught exception: " << ex.what() << std::endl;
    }


    std::cout << "\n13. Void pointer (generic buffer)\n";
    void* buffer = malloc(4);
    int y = 777;
    memcpy(buffer, &y, 4);
    std::cout << "*buffer as int = " << *(int*)buffer << "\n";
    free(buffer);

    return 0;
}
