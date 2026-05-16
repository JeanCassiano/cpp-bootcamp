#include <iostream>
#include <future>
#include <thread>


int somar (int a, int b){
    return a + b;
}

int main(){
    std::packaged_task<int(int, int)> task(somar);

    std::future<int> res = task.get_future();

    std::thread t(std::move(task), 5, 7);

    t.join();

    std::cout << "Resultado: " << res.get() << std::endl;

    return 0;
}