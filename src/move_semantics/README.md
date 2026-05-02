# Move Semantics

A quick reference guide to understanding **Move Semantics** and **Rvalue References** (`&&`) in modern C++ (C++11 and beyond).

In high-performance applications like game engines, copying large chunks of memory (Deep Copies) is a huge bottleneck. Move Semantics allows us to optimize this by transferring ownership of resources from temporary objects to new objects, bypassing the need to copy memory entirely.

## 1. The Core Concept: Copying vs. Moving

Imagine you have a huge box of heavy books. 
* **Copy Semantics:** You buy a new empty box, read every single book in the old box, buy duplicates of each book, and put them in the new box. (Very slow and expensive).
* **Move Semantics:** You just take the label with your name off the old box and slap it onto the new box. The books never moved. (Instant and cheap).

In C++, "books" are dynamically allocated memory (like a huge `int*` array or a 3D model buffer), and "labels" are pointers.

## 2. Rvalues and Lvalues
To understand move semantics, you need to know the difference between Lvalues and Rvalues:
* **Lvalue:** An object that occupies an identifiable location in memory (it has a name). E.g., `int x = 10;` (`x` is an lvalue).
* **Rvalue:** A temporary object that does not have a permanent memory address. E.g., `10` or a temporary object like `GameAsset("Temp")`.

Move semantics specifically target **Rvalues**. If an object is about to be destroyed anyway, it's safe to steal its resources!

## 3. The Move Constructor
A standard Copy Constructor takes a `const Type&` and performs a deep copy. 
A **Move Constructor** takes an **Rvalue Reference** (`Type&&`) and performs a shallow copy of pointers, leaving the source object in a valid but empty state.

### Example:
```cpp
// COPY Constructor (Slow)
MyClass(const MyClass& other) {
    this->data = new int[other.size];
    // ... loop to copy every element ...
}

// MOVE Constructor (Fast)
MyClass(MyClass&& other) noexcept {
    this->data = other.data; // 1. Steal the pointer
    other.data = nullptr;    // 2. Nullify the source (preventing double-freeing)
}
```

## 4. `std::move()`
Sometimes you have an Lvalue (a named object), but you know you won't need it anymore, and you want to move its resources to another object. You can explicitly cast it to an Rvalue using `std::move()`.

> **⚠️ Warning:** `std::move()` does NOT actually move anything! It only casts the object to an rvalue reference (`&&`), telling the compiler: *"Hey, treat this as a temporary object so the Move Constructor can steal from it!"*

### Usage:
```cpp
std::string player1 = "Paladin";
std::string player2 = std::move(player1);

// Now, player2 owns the string memory.
// player1 is now empty/valid but holds no data ("").
```

## The Golden Rules
1. **Rule of Five:** If your class manages manual memory (it has a custom Destructor), you usually need to implement the Copy Constructor, Copy Assignment, Move Constructor, and Move Assignment.
2. **Leave in a valid state:** Always set the stolen pointers in the source object to `nullptr`. Otherwise, when the temporary object's destructor runs, it will delete the memory you just stole!
3. **Use `noexcept`:** Always mark your move constructors as `noexcept`. This tells the standard library (like `std::vector`) that it's safe to move your objects during reallocations instead of copying them.
