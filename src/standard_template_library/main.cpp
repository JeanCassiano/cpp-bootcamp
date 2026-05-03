#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Required for STL algorithms like std::sort, std::find_if

// ==========================================
// DATA CLASS
// ==========================================
struct Item {
    std::string name;
    std::string category;
    int power;
    int value;

    void print() const {
        std::cout << " [" << category << "] " << name 
                  << " (Power: " << power << ", Gold: " << value << ")\n";
    }
};

// ==========================================
// MAIN EXECUTION
// ==========================================
int main() {
    std::cout << "--- OPENING INVENTORY ---\n\n";

    // 1. The STL Container: std::vector
    // Vectors are dynamic arrays. They grow automatically.
    std::vector<Item> inventory = {
        {"Rusty Sword", "Weapon", 5, 10},
        {"Healing Potion", "Consumable", 50, 25},
        {"Nightsong Halberd", "Weapon", 45, 500},
        {"Leather Armor", "Armor", 12, 40},
        {"Fireball Scroll", "Scroll", 30, 100}
    };

    std::cout << "Original Inventory:\n";
    for (const auto& item : inventory) item.print();

    // 2. STL Algorithm + Lambda: SORTING
    // We want to sort the inventory by Power (Descending).
    // The lambda [] (const Item& a, const Item& b) defines the sorting rule.
    std::cout << "\n--- SORTING BY POWER (Highest to Lowest) ---\n";
    
    std::sort(inventory.begin(), inventory.end(), [](const Item& a, const Item& b) {
        return a.power > b.power; 
    });

    for (const auto& item : inventory) item.print();

    // 3. STL Algorithm + Lambda with CAPTURE CLAUSE
    // Let's count how many items are worth MORE than a specific gold amount.
    int minimumGold = 45;
    
    std::cout << "\n--- FILTERING ITEMS (Value > " << minimumGold << " Gold) ---\n";
    
    // The capture clause [minimumGold] allows the lambda to see the local variable!
    int expensiveItemsCount = std::count_if(inventory.begin(), inventory.end(), [minimumGold](const Item& item) {
        return item.value > minimumGold;
    });

    std::cout << "Found " << expensiveItemsCount << " valuable items.\n";

    // 4. STL Algorithm + Lambda: FINDING
    // Let's find the first weapon in the inventory.
    auto it = std::find_if(inventory.begin(), inventory.end(), [](const Item& item) {
        return item.category == "Weapon";
    });

    if (it != inventory.end()) {
        std::cout << "\nFirst weapon found: " << it->name << "!\n";
    }

    std::cout << "\n--- INVENTORY CLOSED ---\n";
    return 0;
}