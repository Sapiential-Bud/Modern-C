//
// Created by WinterRain_Bud on 5/11/2025.
//
#include <iostream>
#include <thread>
#include <vector>

void say_hello(int id) {
    std::cout << "Hello from thread " << id << "!" << std::endl;
}

int main() {
    const int num_threads = 5;
    std::vector<std::thread> threads;

    // Launch threads
    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(say_hello, i);
    }

    // Wait for all threads to finish
    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Main thread done." << std::endl;
    return 0;
}
