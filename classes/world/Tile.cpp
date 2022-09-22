#include <raylib.h>
#include "world/Tile.h"

Tile::Tile()
    {}

Tile::Tile(int isReal){
    this->isReal = isReal;
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
Rectangle Tile::getSource(){
    return source;
}