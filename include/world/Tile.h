#pragma once
#include <raylib.h>

class Tile{
    protected:
        int isReal;
        int width;
        int height;
        Rectangle source;
        Texture2D texture;

    public:
        Tile();
        Tile(int isReal);

        Texture2D getTexture();
        int getWidth();
        int getHeight();
        Rectangle getSource();
};