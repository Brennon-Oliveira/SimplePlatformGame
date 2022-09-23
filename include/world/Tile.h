#pragma once
#include <raylib.h>

class Tile{
    protected:
        int width;
        int height;
        int x;
        int y;
        Rectangle source;
        Texture2D texture;

    public:
        int isReal;
        
        Tile();
        Tile(int isReal, int x, int y);

        Texture2D getTexture();
        int getWidth();
        int getHeight();
        int getX();
        int getY();
        Rectangle getSource();
};