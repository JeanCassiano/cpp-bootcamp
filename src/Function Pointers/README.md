# Pointer to Function

## What is it?
A pointer to function in C++ is a pointer that stores the address of a function. It permits calling function indirectly, stores callbacks e
and selects behavior at runtime.

## Why is it useful?

Pointers to functions help to create a flexible and modular code. They are used in callbacks and to execute functions directly, without using an `if`/`switch` in every call.

## How to use?
- Declare a pointer with the same signature of the function.
- Assign the address of a compatible function
- Call the function through the pointer using `(*ptr)(args)` or `ptr(args)`.


### Example
```cpp
int sum(int a, int b) {
    return a + b;
}

int multiplication(int a, int b) {
    return a * b;
}

int execute(int (*op)(int, int), int x, int y) {
    return (*op)(x, y);
}
```

## When to use?
- Callback functions in algorithms or APIs.
- Dynamic selection of behavior.
- Implementation of function tables and simple plugins.

