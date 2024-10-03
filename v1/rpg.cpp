#include <mcpp/mcpp.h>
#include "../Structures/Structures.h"

class RPG {
    private:
        mcpp::MinecraftConnection mc;
        mcpp::Coordinate origin;
        mcpp::Coordinate pos;

        

    public:
        RPG();
        void TestArea();
        void SetUp();
        void SpawnWave();
};

int main() {
    RPG rpg;
    rpg.TestArea();
    rpg.SetUp();
    rpg.SpawnWave();
}

RPG::RPG() {
    origin = mc.getPlayerTilePosition();
}

void RPG::TestArea() {
    Structure test;
    test.TESTA();
    test.Print(origin, mc);    
}

void RPG::SetUp() {
    // mc.doCommand("gamerule sendCommandFeedback false");
    mc.doCommand("gamerule doWeatherCycle false");
    mc.doCommand("gamerule doDaylightCycle false");
    mc.doCommand("gamerule doMobLoot false");
    mc.doCommand("gamerule doMobSpawning false");
    // mc.doCommand("gamemode adventure @a");
    mc.doCommand("gamerule doFireTick false");
    mc.doCommand("time set night");
    mc.doCommand("effect give @a minecraft:night_vision infinite 1 true");
    mc.doCommand("effect give @a minecraft:saturation 10 10 true");
    mc.doCommand("effect give @a minecraft:regeneration 10 10 true");
    // mc.doCommand("gamerule sendCommandFeedback true");
    
    pos = origin;
    pos.x += 10;
    pos.y += 5;
    pos.z += 10;
    mc.setPlayerPosition(pos);
}