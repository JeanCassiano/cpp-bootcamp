#include <fstream>
#include <iostream>

int main()
{
    // RAII: Resource Acquisition Is Initialization
    // ofstream é um recurso que adquire um arquivo e
    // o libera automaticamente quando sai do escopo.
    std::ofstream file("example.txt");
    if (!file)
    {
        std::cerr << "Não foi possível abrir o arquivo\n";
        return 1;
    }

    file << "Hello RAII\n";
    // O arquivo é fechado automaticamente ao sair do escopo.
}