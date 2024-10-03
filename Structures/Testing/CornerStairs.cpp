#include <mcpp/mcpp.h>

int main() {
    mcpp::MinecraftConnection mc;
    mcpp::Coordinate origin = mc.getPlayerTilePosition();
    mcpp::Coordinate position = origin;

    // std::cout<<mc.getBlock(origin)<<std::endl;

    position.x+=5;
    position.z+=5;

    mcpp::Chunk area = mc.getBlocks(origin,position);

    origin.x += area.x_len() + 5;

    std::vector<mcpp::Coordinate> stairs;

    for (int x = 0; x < area.x_len(); x++) {
        for (int z = 0; z < area.z_len(); z++) {
            position.x = origin.x + x;
            position.z = origin.z + z;
            if (area.get(x,0,z) != mcpp::BlockType(109,0)) {
                // std::cout<<area.get(x,0,z)<<std::endl;
                mc.setBlock(position,area.get(x,0,z));
            } else {
                
                stairs.push_back(mcpp::Coordinate(x,0,z));
            }
        }
    }

    for (mcpp::Coordinate print : stairs) {
        mc.postToChat("Corner or mod 0");
        int x = print.x;
        int z = print.z;
        print.x += origin.x;
        print.y += origin.y;
        print.z += origin.z;

        // std::cout<<print<<std::endl;
        // mc.setBlock(print,mcpp::BlockType(109,0));
        if (area.get(x+1,0,z) == mcpp::BlockType(109,3)){
            mc.setBlock(print,mcpp::BlockType(109,3));
            print.x++;
            mc.setBlock(print,mcpp::Blocks::AIR);
            mc.setBlock(print,mcpp::BlockType(109,3));
        } else if (area.get(x-1,0,z) == mcpp::BlockType(109,3)) {
            mc.setBlock(print,mcpp::BlockType(109,3));
            print.x--;
            mc.setBlock(print,mcpp::Blocks::AIR);
            mc.setBlock(print,mcpp::BlockType(109,3));
        } else if (area.get(x+1,0,z) == mcpp::BlockType(109,2)) {
            mc.setBlock(print,mcpp::BlockType(109,2));
            print.x++;
            mc.setBlock(print,mcpp::Blocks::AIR);
            mc.setBlock(print,mcpp::BlockType(109,2));
        } else if (area.get(x-1,0,z) == mcpp::BlockType(109,2)) {
            mc.setBlock(print,mcpp::BlockType(109,2));
            print.x--;
            mc.setBlock(print,mcpp::Blocks::AIR);
            mc.setBlock(print,mcpp::BlockType(109,2));
        } else if (area.get(x,0,z-1) == mcpp::BlockType(109,1)) {
            mc.setBlock(print,mcpp::BlockType(109,1));
            print.z--;
            mc.setBlock(print,mcpp::Blocks::AIR);
            mc.setBlock(print,mcpp::BlockType(109,1));
        } else if (area.get(x,0,z+1) == mcpp::BlockType(109,1)) {
            mc.setBlock(print,mcpp::BlockType(109,1));
            print.z++;
            mc.setBlock(print,mcpp::Blocks::AIR);
            mc.setBlock(print,mcpp::BlockType(109,1));
        } else if (area.get(x,0,z-1) == mcpp::BlockType(109,0)) {
            mc.setBlock(print,mcpp::BlockType(109,0));
            print.z--;
            mc.setBlock(print,mcpp::Blocks::AIR);
            mc.setBlock(print,mcpp::BlockType(109,0));
        } else if (area.get(x,0,z+1) == mcpp::BlockType(109,0)) {
            mc.setBlock(print,mcpp::BlockType(109,0));
            print.z++;
            mc.setBlock(print,mcpp::Blocks::AIR);
            mc.setBlock(print,mcpp::BlockType(109,0));
        } else {
            mc.setBlock(print,mcpp::BlockType(109,0));
        }
    }
}