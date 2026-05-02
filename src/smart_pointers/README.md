# C++ Smart Pointers Guide 

In modern C++ (C++11 and beyond), manual memory management using `new` and `delete` is highly discouraged due to the risk of memory leaks and dangling pointers. Smart pointers automate memory management by tying the lifecycle of dynamically allocated memory to object scope.

## 1. `std::unique_ptr` (Exclusive Ownership)
The most common, fastest, and safest smart pointer. It enforces **exclusive ownership**: only one `unique_ptr` can point to a specific memory address at a time. When the pointer goes out of scope, the memory is automatically freed.

### Key Characteristics:
* **Zero Overhead:** Almost exactly the same performance as a raw pointer.
* **No Copying:** You cannot copy a `unique_ptr` (this would violate exclusive ownership).
* **Transfer Ownership:** You must use `std::move()` to transfer the data to another `unique_ptr`.

### Example:
```cpp
#include <iostream>
#include <memory>

class Weapon {
public:
    Weapon() { std::cout << "Weapon created\n"; }
    ~Weapon() { std::cout << "Weapon destroyed\n"; }
};

int main() {
    {
        // Always use std::make_unique to create it
        std::unique_ptr<Weapon> sword = std::make_unique<Weapon>();
        
        // Transferring ownership to another unique_ptr
        std::unique_ptr<Weapon> newOwner = std::move(sword);
        
        // 'sword' is now empty (nullptr). 'newOwner' holds the memory.
    } // Memory is automatically freed here when 'newOwner' goes out of scope.
    
    return 0;
}
``` 

## 2. `std::shared_ptr` (Shared Ownership)

Used when multiple objects or functions need to share the exact same piece of data in memory, and the memory should only be freed when all owners are done with it.

### Key Characteristics:
* **Reference Counting**: It keeps a count of how many `shared_ptr`s point to the data.

* **Automatic Deallocation**: The memory is destroyed only when the reference count reaches `0`.

* **Slight Overhead**: The reference counting mechanism uses a tiny bit of extra memory and processing power compared to `unique_ptr`.

### Example:

```cpp
#include <iostream>
#include <memory>

class Texture {
public:
    Texture() { std::cout << "Texture loaded\n"; }
    ~Texture() { std::cout << "Texture freed\n"; }
};

int main() {
    std::shared_ptr<Texture> tex1;

    {
        std::shared_ptr<Texture> tex2 = std::make_shared<Texture>();
        tex1 = tex2; // Reference count is now 2
        std::cout << "Owners: " << tex1.use_count() << "\n";
    } // tex2 goes out of scope. Reference count drops to 1. Memory is NOT freed.

    std::cout << "Owners: " << tex1.use_count() << "\n";
    return 0; // tex1 goes out of scope. Count drops to 0. Memory is freed here.
}
```

## 3. `std::weak_ptr` (The Observer)

A companion to `shared_ptr`. It allows you to look at the data managed by a shared_ptr without increasing the reference count. It is mainly used to break cyclic references (e.g., Player points to Inventory, and Inventory points back to Player, causing a memory leak).

## The Golden Rules of Modern C++
1. Never use new and delete.

2. Use `std::unique_ptr` by default for everything.

3. Upgrade to `std::shared_ptr` only if you logically require multiple owners for the exact same resource.