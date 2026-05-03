# C++ STL & Lambdas

A quick reference guide to using the **Standard Template Library (STL)** and **Lambda Expressions** in modern C++ (C++11 and beyond). 

When building games or high-performance software, you rarely need to write your own sorting or searching loops from scratch. The STL provides highly optimized algorithms, and Lambdas allow you to customize exactly how those algorithms behave on the fly.

## 1. What is the STL?
The **Standard Template Library** is a massive collection of ready-to-use C++ tools. It is divided into three main parts:
1. **Containers:** Data structures that store collections of items (e.g., `std::vector`, `std::map`, `std::set`).
2. **Iterators:** Objects that allow you to safely traverse these containers (e.g., `inventory.begin()`).
3. **Algorithms:** Highly optimized functions that perform operations on containers (e.g., `std::sort`, `std::find_if`, `std::remove_if`).

## 2. What is a Lambda Expression?

A Lambda is simply an **anonymous function** (a function without a name) that you write directly inside your code, right where you need it. 

Before Lambdas, if you wanted to sort an array of objects by a specific rule, you had to declare a separate function outside of `main()`. Now, you can inject the logic directly into the STL algorithm.

### The Lambda Syntax: `[] () {}`
A lambda consists of three main parts:
* `[]` **The Capture Clause:** Defines what outside variables the lambda is allowed to see.
* `()` **The Parameters:** The variables the lambda receives when it is called (just like a normal function).
* `{}` **The Body:** The actual code/logic of the function.

### Example:
```cpp
auto attack = [](int damage) {
    std::cout << "You hit for " << damage << " points!\n";
};

attack(50); // Calling the lambda
```

## 3. The Power of the Capture Clause `[]`
If you write a normal function, it cannot see the local variables inside `main()`. Lambdas *can*, if you capture them!

* `[]` : Captures nothing. The lambda can only use its parameters.
* `[x]` : Captures the variable `x` by **value** (a read-only copy).
* `[&x]` : Captures the variable `x` by **reference** (allows the lambda to modify the original variable).
* `[=]` : Captures ALL local variables by **value**.
* `[&]` : Captures ALL local variables by **reference**.

### Example in Action (Filtering):
```cpp
int threshold = 10;

// We use [threshold] to pass the local variable inside the lambda!
int strongEnemies = std::count_if(enemies.begin(), enemies.end(), [threshold](const Enemy& e) {
    return e.level > threshold;
});
```

## The Golden Rules 
1. **Never write raw loops for searching/sorting.** If you need to find an item, count enemies, or sort scores, use `<algorithm>`. It is faster, safer, and easier to read.
2. **Pass large objects by `const &` in lambdas.** When writing `[](const Item& a)`, the `const &` ensures you aren't accidentally copying heavy 3D models or textures just to check their values.
3. **Keep lambdas short.** If your lambda body is more than 5-10 lines long, it is usually better to write a proper named function to keep your code clean.
