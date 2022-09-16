#include <raylib.h>
#include <raymath.h>
#include "../entities/player/Player.cpp"

class Game {
    public:

        Player* player;

        Game(){
            InitWindow(Consts::getWidth(), Consts::getHeight(), Consts::getTitle());            
            SetTargetFPS(Consts::getFps());
            this->player = new Player(30, 30);
            
            this->clock();
        }

    private:
        void clock(){
            while (!WindowShouldClose())
            {
                this->update();
                this->draw();
            }
        }

        void update(){
            this->player->update();
        }

        void draw(){
            BeginDrawing();
                ClearBackground(WHITE);
                
                
                this->player->draw();
            EndDrawing();
        }
};