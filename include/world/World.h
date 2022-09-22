#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <new>
#include "world/Tile.h"
// #include "world/tilesTypes/Wall.h"
// #include "world/tilesTypes/Floor.h"
// using namespace std;

class World{
    private:
        std::ifstream levelFile;
        char *levelData;
        int mapSize = 0;
        int mapWidth = 0;
        Tile *tilemap;

    public:
        World();

        void construct(int level);

        void loadMap();

        void defineTilemap();

        Tile defineTileType(char type);

        void draw();
};