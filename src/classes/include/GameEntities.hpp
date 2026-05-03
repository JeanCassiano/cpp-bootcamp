#pragma once
#include <iostream>
#include <string>
#include <vector>

// INTERFACE (Abstraction at its highest level)
// In C++, an interface is an abstract class with only pure virtual functions.
class IDamageable {
public:
    virtual ~IDamageable() = default;
    virtual void takeDamage(int amount) = 0; 
};

// CLASS (Base component for Composition)
// This class will be strictly owned by another class.
class Attributes {
public:
    int strength;
    int charisma;
    Attributes(int str, int cha);
};

// CLASS (Base component for Association)
// This class exists independently and can be used by others.
class Weapon {
private:
    std::string name;
    int damage;
public:
    Weapon(std::string name, int damage);
    std::string getName() const;
    int getDamage() const;
};

// CLASS & ABSTRACTION & ENCAPSULATION
// Abstract base class demonstrating Encapsulation (private members).
class Character : public IDamageable {
private: 
    // Encapsulation: State is hidden and protected.
    std::string name;
    int hp;

    // 7. COMPOSITION (Strong "Has-A" relationship)
    // The Character OWNS the Attributes. If Character dies, Attributes die.
    Attributes stats; 

public:
    Character(std::string name, int hp, int str, int cha);
    virtual ~Character() = default;

    // Encapsulation: Public interfaces to interact with private data.
    std::string getName() const;
    int getHp() const;

    // Interface Implementation
    void takeDamage(int amount) override;

    // Abstraction & Polymorphism: Pure virtual function to be overridden.
    virtual void performAction() const = 0; 
};

// INHERITANCE
// Paladin inherits from Character.
class Paladin : public Character {
private:
    // ASSOCIATION ("Uses-A" relationship)
    // The Paladin uses a Weapon, but the Weapon exists independently.
    Weapon* equippedWeapon; 

public:
    Paladin(std::string name, int hp, int str, int cha);

    void equip(Weapon* weapon);
    
    // POLYMORPHISM
    // Overriding the base class method with specific behavior.
    void performAction() const override; 
};

// AGGREGATION (Weak "Has-A" relationship)
// The Party HAS Characters, but it doesn't own their lifecycle. 
// If the Party is disbanded, the Characters still exist.
class Party {
private:
    std::vector<Character*> members;
public:
    void addMember(Character* character);
    void displayPartyActions() const;
};