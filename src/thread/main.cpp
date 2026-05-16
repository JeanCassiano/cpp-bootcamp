#include <iostream>
#include <vector>
#include <thread>

int main(){
    std::vector<std::thread> threads;
    int i;
    auto my_function = [](int i){
        std::cout << "Thread [" << i << "] rodando!\n"; 
    };

    for (i = 0; i < 5; i++){
        threads.emplace_back(my_function, i);
    }

    for (std::thread& t : threads){
        t.join();
    }
    return 0;
}