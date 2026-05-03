#include <iostream>
#include "../include/GameEntities.hpp"

int main() {
    std::cout << "Starting OOP Demonstration Game...\n\n";

    // 1. OBJECTS
    // Instantiating objects from our classes.
    Weapon mace("Mace of the Absolute", 15);
    
    // Minthara is a Paladin (Inheritance). 
    // She contains her Attributes implicitly (Composition).
    Paladin minthara("Minthara", 100, 18, 16); 
    
    // 2. ASSOCIATION
    // Minthara interacts with the Weapon, but the weapon exists on its own.
    minthara.equip(&mace);

    // 3. AGGREGATION
    // Creating a Party and adding members. The pointers are aggregated.
    Party myParty;
    myParty.addMember(&minthara);

    // 4. POLYMORPHISM & ABSTRACTION
    // The Party uses Character pointers to trigger Paladin-specific behavior.
    myParty.displayPartyActions();

    // 5. INTERFACE & ENCAPSULATION
    // Accessing private health via public getter, and using the IDamageable interface.
    std::cout << "\nEnemy strikes!\n";
    minthara.takeDamage(20);
    
    return 0;
}