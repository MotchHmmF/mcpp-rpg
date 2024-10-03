#include <mcpp/mcpp.h>

int main() {
    mcpp::MinecraftConnection mc;

    mcpp::Coordinate origin = mc.getPlayerPosition();
    mcpp::Coordinate printer = origin;
    // for (int id = 0; id < 256; id++) {
    //     mc.postToChat(std::to_string(id));
    //     if (id == 8 || id == 9 || id == 10 || id == 11) continue;
    //     if (id == 253 || id == 254) continue;

    //     if (id%20==0) mc.setPlayerTilePosition(printer);

    //     for (int mod = 0; mod < 16; mod++) {
    //         // mc.postToChat(std::to_string(mod));
    //         mc.setBlock(printer,mcpp::BlockType(id,mod));
    //         if (mod != 0 && mc.getBlock(printer).mod == 0) {
    //             mc.setBlock(printer,mcpp::Blocks::AIR);
    //             break;
    //         }
    //         printer.z += 2;
    //     }
    //     printer.z = origin.z;
    //     printer.x += 2;
    // }

    for (int i = 0; i < 16; i++) {
        printer.x+=2;
        mc.setBlock(printer,mcpp::BlockType(144,i));
    }
}