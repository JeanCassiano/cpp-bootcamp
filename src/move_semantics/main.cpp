#include <iostream>
#include <vector>
#include <string>

class GameAsset {
private:
    std::string name;
    int* heavyData; // Simulating a heavy 3D model or large texture
    size_t dataSize;

public:
    // 1. Regular Constructor
    GameAsset(std::string n, size_t size) : name(n), dataSize(size) {
        std::cout << "[INIT] Creating heavy asset: " << name << " (" << dataSize << " elements)\n";
        heavyData = new int[dataSize];
        // Simulating filling the data
        for (size_t i = 0; i < dataSize; ++i) heavyData[i] = i;
    }

    // 2. Destructor
    ~GameAsset() {
        if (heavyData != nullptr) {
            std::cout << "[DESTROY] Freeing memory for: " << name << "\n";
            delete[] heavyData;
        } else {
            std::cout << "[DESTROY] Destroying empty shell of: " << name << "\n";
        }
    }

    // 3. COPY Constructor (Deep Copy - SLOW)
    // Used when we duplicate the object. We must allocate new memory and copy everything.
    GameAsset(const GameAsset& other) : name(other.name + " (Copy)"), dataSize(other.dataSize) {
        std::cout << "  -> [COPY] Deep copying data for: " << name << " (EXPENSIVE!)\n";
        heavyData = new int[dataSize];
        for (size_t i = 0; i < dataSize; ++i) {
            heavyData[i] = other.heavyData[i];
        }
    }

    // 4. MOVE Constructor (Move Semantics - FAST)
    // Used when 'other' is a temporary object (rvalue). We just steal its pointers!
    GameAsset(GameAsset&& other) noexcept : name(other.name), dataSize(other.dataSize) {
        std::cout << "  -> [MOVE] Stealing pointers from: " << name << " (SUPER FAST!)\n";
        
        // Steal the pointer to the heavy data
        heavyData = other.heavyData;
        
        // Nullify the source object's pointer so its destructor doesn't free our stolen memory!
        other.heavyData = nullptr;
        other.dataSize = 0;
        other.name = "Moved_Out_Asset";
    }
};

int main() {
    std::cout << "--- LEVEL LOADING SEQUENCE ---\n\n";

    // Creating an initial asset
    GameAsset bossModel("Dragon_Model_3D", 500000);

    std::cout << "\n--- Scenario A: Copying an Asset ---\n";
    // We want a second dragon. This forces a Deep Copy.
    GameAsset bossClone = bossModel; 

    std::cout << "\n--- Scenario B: Moving an Asset ---\n";
    // We create a temporary object (anonymous GameAsset) and push it into a vector.
    // Instead of copying the temporary data, C++ MOVES it into 'activeModel'.
    GameAsset activeModel = std::move(GameAsset("Giant_Sword_Texture", 1000000));

    std::cout << "\n--- END OF SCOPE (Cleanup) ---\n";
    return 0;
} 