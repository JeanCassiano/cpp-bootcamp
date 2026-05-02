#include <iostream>
#include <memory>
#include <string>
#include <vector>

// ==========================================
// DATA CLASSES
// ==========================================

class Weapon {
public:
    std::string name;
    Weapon(std::string n) : name(n) { 
        std::cout << "  [Memory] Weapon '" << name << "' forged.\n"; 
    }
    ~Weapon() { 
        std::cout << "  [Memory] Weapon '" << name << "' destroyed.\n"; 
    }
};

class MagicAura {
public:
    std::string type;
    MagicAura(std::string t) : type(t) { 
        std::cout << "  [Memory] Aura of '" << type << "' conjured.\n"; 
    }
    ~MagicAura() { 
        std::cout << "  [Memory] Aura of '" << type << "' dissipated.\n"; 
    }
};

// ==========================================
// CHARACTER CLASS
// ==========================================

class Character {
public:
    std::string name;
    
    // unique_ptr: ONLY THIS character owns the weapon.
    std::unique_ptr<Weapon> equippedWeapon;
    
    // shared_ptr: This aura can be shared with other party members.
    std::shared_ptr<MagicAura> activeAura;

    Character(std::string n) : name(n) { 
        std::cout << "[Party] " << name << " joined the party.\n"; 
    }
    ~Character() { 
        std::cout << "[Party] " << name << " left the party.\n"; 
    }

    // To pass a unique_ptr, we must use std::move() to transfer ownership
    void equipWeapon(std::unique_ptr<Weapon> newWeapon) {
        equippedWeapon = std::move(newWeapon);
        std::cout << name << " equipped the weapon: " << equippedWeapon->name << ".\n";
    }

    void receiveAura(std::shared_ptr<MagicAura> aura) {
        activeAura = aura;
        std::cout << name << " is under the effect of the aura: " << activeAura->type << ".\n";
    }
};

// ==========================================
// MAIN EXECUTION
// ==========================================

int main() {
    std::cout << "--- STARTING THE ADVENTURE ---\n\n";

    // Creating a shared aura (shared_ptr)
    std::shared_ptr<MagicAura> divineProtection = std::make_shared<MagicAura>("Divine Protection");

    {
        // Creating characters
        Character minthara("Minthara");
        Character halsin("Halsin");

        // Creating exclusive weapons (unique_ptr)
        std::unique_ptr<Weapon> staff = std::make_unique<Weapon>("Oak Staff");
        std::unique_ptr<Weapon> mace = std::make_unique<Weapon>("Night Mace");

        // Equipping weapons (we use std::move because the weapon has an exclusive owner)
        minthara.equipWeapon(std::move(mace));
        halsin.equipWeapon(std::move(staff));

        std::cout << "\n--- APPLYING AOE BUFFS ---\n";
        
        // Both receive the SAME aura (sharing ownership)
        minthara.receiveAura(divineProtection);
        halsin.receiveAura(divineProtection);

        std::cout << "Aura owner count: " << divineProtection.use_count() << "\n\n";

        std::cout << "--- HALSIN FELL IN BATTLE (Going out of scope) ---\n";
        // Halsin's scope will end soon, what happens to the memory?
    } 
    // END OF BLOCK: 'minthara' and 'halsin' are destroyed.
    // Their exclusive weapons (unique_ptr) are automatically destroyed along with them!
    // However, 'divineProtection' STILL EXISTS in main(), so it's not destroyed yet.

    std::cout << "\nAura owner count in main: " << divineProtection.use_count() << "\n";
    std::cout << "--- GAME OVER ---\n";

    return 0;
} // main() ends here, 'divineProtection' loses its last owner and is destroyed!