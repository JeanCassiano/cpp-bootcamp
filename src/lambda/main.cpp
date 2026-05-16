#include <iostream>
#include <string>
int main(){
    auto hello = [](){
        std::cout << "Hello!\n";
    };

    hello();


    auto hello_name = [](std::string s){
        std::cout << "Hello, " << s << std::endl;
    };

    hello_name("Jean");
    int contador = 9;
    auto sum_integer = [&contador](int a, int b){
        contador += a + b;
    };

    sum_integer(7, 8);
    std::cout << contador << std::endl;
    return 0;
}