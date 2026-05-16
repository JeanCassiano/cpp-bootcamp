#include <iostream>
#include <thread>
#include <condition_variable>
#include <chrono>
#include <mutex>

int main(){
    std::mutex  mtx;
    std::condition_variable cv;
    bool acordar = false;

    std::thread t([&](){
        std::unique_lock<std::mutex> lock(mtx);

        cv.wait(lock, [&](){return acordar;});

        std::cout << "Fui acordada!" << std::endl;
    });

    std::this_thread::sleep_for(std::chrono::seconds(2));
    

    {
        std::lock_guard<std::mutex> lock(mtx);
        acordar = true;
    }

    cv.notify_one();

    t.join();


    return 0;
}