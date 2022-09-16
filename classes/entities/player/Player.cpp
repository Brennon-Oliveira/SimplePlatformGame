#include <raylib.h>
#include <string>

class Player{
    protected:
        // Player Values
        Vector2 position;
        int speed = 2;
        int isMoving = 0;

        // Graphics
        float width = 32;
        float height = 32;
        Rectangle spriteRec = {0,0,width,height};
        int direction = 1;

        // Animation
        const int frameDuration = 4;
        int frameTimer = 0;
        int frames;
        int curFrame;
        std::string lastAnimation;
        std::string callAnimation;
        
        // sprite
        Texture2D curTexture;

    public:
        Player(int x, int y){
            position.x = x;
            position.y = y;
        }

        void update(){
            callAnimation = "idle";
            move();
            animationControll();            
            animationUpdate();
        }

        void draw(){
            spriteRec.width = width*direction;
            DrawTextureRec(curTexture, spriteRec, position, WHITE);
        }
    private:

        void move(){
            if(IsKeyDown(KEY_LEFT)){
                isMoving = 1;
                direction = -1;
                callAnimation = "running";
            } else if(IsKeyDown(KEY_RIGHT)){
                isMoving = 1;
                direction = 1;
                callAnimation = "running";
            } else {
                isMoving = 0;
            }
            position.x += speed * direction * isMoving;
        }

        void animationUpdate(){
            if(++frameTimer == frameDuration){
                frameTimer = 0;
                if(++curFrame > frames){
                    curFrame = 0;
                }
            }
            spriteRec.x = curFrame * spriteRec.width;
        }

        void animationControll(){
            if(callAnimation == lastAnimation) return;
            curFrame = 0;
            if(callAnimation == "idle"){
                frames = 11;
                lastAnimation = callAnimation;
                curTexture = LoadTexture("./assets/MainCharacters/VirtualGuy/Idle.png");;
            }
            if(callAnimation == "running"){
                frames = 12;
                lastAnimation = callAnimation;
                curTexture = LoadTexture("./assets/MainCharacters/VirtualGuy/Running.png");;
            }
        }
};