#include <raylib.h>
#include "world/tilesTypes/Floor.h"

Floor::Floor(int isReal): Tile(isReal){
    this->texture = LoadTexture("./assets/Terrain/Terrain.png");
    this->width = 16;
    this->height = 16;
    this->source = Rectangle{
        (float)12*width,
        (float)1*height,
        (float)width,
        (float)height
    };
}