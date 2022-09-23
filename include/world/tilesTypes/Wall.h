#pragma once
#include "world/Tile.h"

class Wall:public Tile{
    public:
        Wall(int isReal, int x, int y);

};
