#include <mcpp/mcpp.h>

int main() {
    mcpp::MinecraftConnection mc;
    mcpp::Coordinate position = mc.getPlayerTilePosition();

    for (int x = 0; x < 3; x++) {
        for (int z = 0; z < 7; z++) {
            std::cout<<mc.getBlock(position)<<std::endl;
            position.z++;
        }
        position.z-=7;
        position.x++;
    }
}