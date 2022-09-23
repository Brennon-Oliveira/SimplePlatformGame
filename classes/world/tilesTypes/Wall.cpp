#include <raylib.h>
#include "game/TextureLoader.h"
#include "world/tilesTypes/Wall.h"

Wall::Wall(int isReal, int x, int y): Tile(isReal, x, y){
    this->texture = TextureLoader::wallTexture;
    this->width = 16;
    this->height = 16;
    this->source = Rectangle{
        0,
        0,
        (float)width,
        (float)height
    };
}