#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::mutex mutex_counter;

int main() {
    std::vector<std::thread> threads;
    int contador = 0;

    auto increment_to_1000000 = [](int& contador) {
        for (int i = 0; i < 1000000; i++) {
            std::unique_lock<std::mutex> lock(mutex_counter);
            contador++;
        }
    };

    for (int i = 0; i < 16; i++) {
        threads.emplace_back(increment_to_1000000, std::ref(contador));
    }

    for (std::thread& t : threads) {
        t.join();
    }

    std::cout << contador << std::endl;
}