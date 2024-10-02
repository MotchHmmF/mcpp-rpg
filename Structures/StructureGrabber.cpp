#include <mcpp/mcpp.h>
#include <unistd.h>
#include <iostream>
#include <fstream>

#define pos mcpp::Blocks::PURPLE_WOOL
#define air mcpp::Blocks::AIR
#define spawner mcpp::Blocks::MONSTER_SPAWNER

mcpp::Coordinate PosSelector(mcpp::MinecraftConnection& mc){
    mcpp::Coordinate position;
    while (true) {
        position = mc.getPlayerTilePosition();
        // origin.y--;
        if (mc.getBlock(position) == pos) {
            mc.setBlock(position,air);
            break;
        }
        usleep(50000);
    }
    return position;
}

int main () {
    std::string FS = "../Structures/Structures.h";

    mcpp::MinecraftConnection mc;

    mcpp::Coordinate origin;
    mcpp::Coordinate oposite;
    mcpp::Coordinate confirm;

    mc.postToChat("Origin Corner: Please stand on a purple wool");
    origin = PosSelector(mc);
    mc.postToChat("Origin Corner Selected");

    mc.postToChat("Opposite Corner: Please stand on a purple wool");
    oposite = PosSelector(mc);
    mc.postToChat("Opposite Corner Selected");

    mc.postToChat("Please Clear Area: Then stand on another purple wool");
    confirm = PosSelector(mc);
    mc.postToChat("Confirmation complete, Grabbing area");

    mcpp::Chunk area = mc.getBlocks(origin,oposite);

    std::ofstream outFS;
    outFS.open(FS, std::ios::app);

    if (!outFS.is_open()){
        mc.postToChat("File Failed to open.");
        return 1;
    }
    outFS <<    "\nvoid Structure::RENAME_ME() {\n"
                "    X_SIZE = " << area.x_len() << ";\n"
                "    Y_SIZE = " << area.y_len() << ";\n"
                "    Z_SIZE = " << area.z_len() << ";\n"
                "    blocks.clear();\n"
                "    blocks={";

    std::vector<int*> spawnerLocations;

    for (int x = 0; x < area.x_len(); x++) {
        for (int y = 0; y < area.y_len(); y++) {
            for (int z = 0; z < area.z_len(); z++) {
                mcpp::BlockType block = area.get(x,y,z);
                if (block != spawner) {
                    if ((x+y+z) != 0) outFS << ",";
                    outFS << "mcpp::BlockType(" << block.id 
                          << "," << block.mod << ")";
                } else {
                    spawnerLocations.push_back(new int[3]{x,y,z});
                    outFS << ",mcpp::BlockType(0,0)";
                }
            }
        }
    }
    outFS <<    "};\n"
                "    spawners.clear();\n"
                "    spawners={";

    for (size_t i = 0; i < spawnerLocations.size(); i++) {
        int* coords = spawnerLocations.at(i);
        if (i!=0) outFS << ",";
        outFS << "mcpp::Coordinate(" << coords[0] << "," 
              << coords[1] << "," << coords[2] << ")";
    }

    outFS << "};\n"
             "}\n";
    outFS.close();

    mc.postToChat("Grab Completed");
}
    