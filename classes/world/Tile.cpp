#include <raylib.h>

class Tile{
    protected:
        int isReal;
        int width;
        int height;
        Rectangle source;
        Texture2D texture;

    public:
        Tile(){};
        Tile(int isReal){
            this->isReal = isReal;
        }

        Texture2D getTexture(){
            return texture;
        }
        int getWidth(){
            return height;
        }
        int getHeight(){
            return width;
        }
        Rectangle getSource(){
            return source;
        }
};