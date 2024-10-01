#include <mcpp/mcpp.h>

class RPG {
    private:
        mcpp::MinecraftConnection mc;
        mcpp::Coordinate origin;
        mcpp::Coordinate printer;

        double difficultyMultiplier;
        double shopPrices;
        int startingEquipment;

    public:
        RPG();
        void SelectSettings();
        void TestArea();
};

int main() {
    RPG rpg;
    rpg.SelectSettings();
    rpg.TestArea();
}

RPG::RPG() {
    origin = mc.getPlayerTilePosition();
}

void RPG::SelectSettings() {
    // Create a thing that builds the settings area
    difficultyMultiplier = 1;
    shopPrices = 1.0;
    startingEquipment = 1;
}

void RPG::TestArea() {
    printer = origin;
    printer.x += 50;
    printer.z += 50;
    
}
