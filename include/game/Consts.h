#include <raylib.h>
#include <string>

class Consts {
    private:
        char *TITLE = "Simple Platform Game";
        int WIDTH = GetScreenWidth();
        int HEIGHT = GetScreenHeight();
        int FPS = 200;
        float GRAVITY = 300;
        float SCALE = 2;
    public:
        static char * getTitle(){
            Consts consts;
            return consts.TITLE;
        }
        static int getWidth(){
            Consts consts;
            return consts.WIDTH;
        }
        static int getHeight(){
            Consts consts;
            return consts.HEIGHT;
        }
        static int getFps(){
            Consts consts;
            return consts.FPS;
        }
        static int getScale(){
            Consts consts;
            return consts.SCALE;
        }
        static float getGravity(){
            Consts consts;
            return consts.SCALE;
        }
};
