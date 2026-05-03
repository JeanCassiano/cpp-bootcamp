#include "../include/GameEntities.hpp"

// --- Attributes Implementation ---
Attributes::Attributes(int str, int cha) : strength(str), charisma(cha) {}

// --- Weapon Implementation ---
Weapon::Weapon(std::string name, int damage) : name(name), damage(damage) {}
std::string Weapon::getName() const { return name; }
int Weapon::getDamage() const { return damage; }

// --- Character Implementation ---
Character::Character(std::string name, int hp, int str, int cha) 
    : name(name), hp(hp), stats(str, cha) {} // Instantiating Composition here

std::string Character::getName() const { return name; }
int Character::getHp() const { return hp; }

void Character::takeDamage(int amount) {
    hp -= amount;
    if (hp < 0) hp = 0;
    std::cout << name << " took " << amount << " damage! HP is now " << hp << ".\n";
}

// --- Paladin Implementation ---
Paladin::Paladin(std::string name, int hp, int str, int cha)
    : Character(name, hp, str, cha), equippedWeapon(nullptr) {}

void Paladin::equip(Weapon* weapon) {
    equippedWeapon = weapon;
    std::cout << getName() << " equipped " << weapon->getName() << ".\n";
}

void Paladin::performAction() const {
    std::cout << getName() << " uses Divine Smite! ";
    if (equippedWeapon) {
        std::cout << "Dealing " << equippedWeapon->getDamage() + 10 << " radiant damage.\n";
    } else {
        std::cout << "Dealing 10 bare-handed radiant damage.\n";
    }
}

// --- Party Implementation ---
void Party::addMember(Character* character) {
    members.push_back(character);
    std::cout << character->getName() << " joined the party.\n";
}

void Party::displayPartyActions() const {
    std::cout << "\n--- Party is attacking! ---\n";
    for (const auto& member : members) {
        // Polymorphism in action: calling the method via base class pointer
        member->performAction(); 
    }
    std::cout << "---------------------------\n";
}