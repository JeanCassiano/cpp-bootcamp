# Function Templates

## What are they?

Function Templates are a C++ feature that allows developers to write a single function capable of operating on different types of data. This means you don't need to create multiple overloaded functions with different parameter types. You create only one "generic" template. The compiler then uses this template to automatically generate the correct version of the function based on the data type passed to it.

## Why do they matter?

They automate code generation and prevent duplication, enforcing the DRY (Don't Repeat Yourself) principle. This drastically simplifies system maintenance. Additionally, they guarantee type safety at compile time, making them a much superior and safer alternative to macros (`#define`) or generic pointers (`void*`).

## How to use them?

To use a Function Template, declare the `template` keyword followed by the type parameters enclosed in angle brackets (`< >`), using either `typename` or `class`. Then, write the function using this generic type.
```cpp
template <typename T>
T max_value(T a, T b) {
    return (a > b) ? a : b;
}

// The compiler automatically deduces the type during usage