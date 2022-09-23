#include <raylib.h>
#include "world/Tile.h"

Tile::Tile()
    {}

Tile::Tile(int isReal, int x, int y){
    this->isReal = isReal;
    this->x = x;
    this->y = y;
}

Texture2D Tile::getTexture(){
    return texture;
}
int Tile::getWidth(){
    return height;
}
int Tile::getHeight(){
    return width;
}
int Tile::getX(){
    return x;
}
int Tile::getY(){
    return y;
}
Rectangle Tile::getSource(){
    return source;
}