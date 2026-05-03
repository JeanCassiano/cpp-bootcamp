## OOP Concepts 

### 1. Class
A **Class** is a blueprint for creating objects. In this project, `Character`, `Weapon`, and `Attributes` are classes that define the properties and behaviors of entities.

### 2. Object
An **Object** is an instance of a class. In `main.cpp`, `minthara` is an object of the `Paladin` class, and `mace` is an object of the `Weapon` class.

### 3. Abstraction
**Abstraction** involves hiding complex implementation details and showing only the necessary features. The `Character` class is abstract because it represents a general concept that cannot be instantiated on its own (marked by pure virtual functions).

### 4. Encapsulation
**Encapsulation** is the bundling of data and methods that operate on that data, restricting direct access. We use `private` members (like `hp` and `name`) and provide `public` methods (getters and setters) to interact with them safely.

### 5. Interface
An **Interface** in C++ is an abstract class containing only pure virtual functions. `IDamageable` acts as a contract, ensuring that any class inheriting from it MUST implement the `takeDamage` method.

### 6. Inheritance
**Inheritance** allows a class to derive attributes and methods from another. `Paladin` inherits from `Character`, gaining its name, health, and base mechanics while adding specific Paladin behaviors.

### 7. Polymorphism
**Polymorphism** allows one interface to be used for a general class of actions. In the `Party` class, we call `member->performAction()`. Even though `member` is a `Character*`, C++ dynamically executes the `Paladin` version of the function at runtime.

### 8. Composition ("Has-A" Strong)
**Composition** is a strong relationship where the life of the child object depends on the parent. The `Character` class **is composed of** `Attributes`. If a `Character` is destroyed, its `Attributes` are destroyed with it.

### 9. Aggregation ("Has-A" Weak)
**Aggregation** is a weak relationship where the child can exist independently of the parent. The `Party` class uses aggregation to hold `Character` objects. If the `Party` is disbanded, the `Character` objects still exist in memory.

### 10. Association ("Uses-A")
**Association** defines a relationship between two independent classes. A `Paladin` is **associated** with a `Weapon`. The Paladin uses the weapon to attack, but they are not part of each other's lifecycle.

---

## How to Compile and Run

To compile the project using G++, navigate to the `classes/` folder and run:

```bash
# 1. Create a build directory
mkdir build
cd build

# 2. Generate the build files
cmake ..

# 3. Compile the project
cmake --build .

# 4. Run the executable
./rpg_demo       # On Linux/macOS
# .\rpg_demo.exe # On Windows
```

## Code Implementation Details
- **Header Files**: Used for declarations to speed up compilation and organize code.
- **Virtual Destructors**: Essential when using Polymorphism to prevent memory leaks.
- **Override Keyword**: Used to ensure we are correctly overriding base class methods.
