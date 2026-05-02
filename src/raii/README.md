# RAII

## What is RAII?

Resource Acquisition Is Initialization (is a technique) in C++ where resources are automatically managed through object lifetime. Simply put, resources get acquired during object creation (initialization) and automatically released when the object goes out of scope (destruction).

## Why RAII Matters?

RAII automates resource management, preventing leaks by tying resource lifetimes to object scope. RAII drastically simplifies resource cleanup and reduces human error.

## How to use it?

To use RAII, wrap each resource in a class whose constructor acquires the resource and whose destructor releases it. This pattern ensures the resource is freed automatically when the object goes out of scope, even if an exception is thrown.

### Common RAII resources

- Memory allocations
- File handles
- Sockets
- Mutex locks
- Database connections

### Best practices

- Make resource-managing classes non-copyable or implement move semantics.
- Prefer standard RAII types when available, such as `std::unique_ptr`, `std::lock_guard`, `std::ifstream`, and `std::ofstream`.
- Keep construction and destruction simple and exception-safe.

## Summary

RAII binds resource lifetime to object lifetime, making code safer and easier to maintain. When you follow RAII, cleanup happens automatically and you avoid common mistakes like forgetting to release a resource.

