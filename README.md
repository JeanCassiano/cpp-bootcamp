# C++ Bootcamp

## Overview
A hands-on repository dedicated to studying and implementing core concepts in C++. This project serves as a structured environment for exploring systems programming, algorithm optimization, and object-oriented design.

## Topics Covered
* **Memory Management:** Raw pointers, dynamic allocation, and memory safety.
* **Data Structures:** Custom implementations of foundational structures (Linked Lists, Trees, Hash Maps).
* **Modern C++:** Practical application of C++17 and C++20 features.
* **Algorithms:** Solutions to classic computational and logic problems.


Faz todo o sentido! Como você tem um `CMakeLists.txt` na raiz do projeto gerenciando vários executáveis de diferentes módulos do seu bootcamp, é ideal ter uma seção no seu **`README.md` principal** explicando como compilar tudo de uma vez.

Aqui está o bloco em Markdown pronto para você adicionar no seu arquivo principal:

## How to Compile and Run 

To compile the code, navigate to the **root directory** of the project and execute the following commands:
```bash
# 1. Create a build directory
mkdir build
cd build

# 2. Generate the build files using modern C++ (C++20)
cmake ..

# 3. Compile all the modules
cmake --build .
```

Once the compilation is complete, all executables will be available in the `build` directory. You can run each specific topic by calling its respective executable:

- **Function Pointers:** `./pointers`
- **Function Templates:** `./templates`
- **RAII:** `./raii`
- **Smart Pointers:** `./smartpointers`
- **Standard Template Library (STL):** `./sts`
- **Move Semantics:** `./move`

*(Note: If you are on Windows, you might need to use `.\pointers.exe`, etc.)*


## Tech Stack
* C++ (C++17/C++20)
* CMake
* GCC / GNU Make
* Linux / WSL2


