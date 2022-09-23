#pragma once
#include "world/Tile.h"

class Floor: public Tile{
    public: 
        Floor(int isReal, int x, int y);
};
