#include <raylib.h>
#include "game/TextureLoader.h"
#include "world/tilesTypes/Floor.h"

Floor::Floor(int isReal, int x, int y): Tile(isReal, x, y){
    this->texture = TextureLoader::floorTexture;
    this->width = 16;
    this->height = 16;
    this->source = Rectangle{
        (float)12*width,
        (float)1*height,
        (float)width,
        (float)height
    };
}