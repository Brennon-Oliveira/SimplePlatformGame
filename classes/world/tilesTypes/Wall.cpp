#include <raylib.h>
#include "world/tilesTypes/Wall.h"

Wall::Wall(int isReal): Tile(isReal){
    this->texture = LoadTexture("./assets/Background/Yellow.png");
    this->width = 16;
    this->height = 16;
    this->source = Rectangle{
        0,
        0,
        (float)width,
        (float)height
    };
}