#include <raylib.h>
#include <raymath.h>
#include "../entities/player/Player.cpp"
#include "../world/World.cpp"

class Game {
    public:

        Player* player;
        World curWorld;

        Game(){
            InitWindow(Consts::getWidth(), Consts::getHeight(), Consts::getTitle());            
            SetTargetFPS(Consts::getFps());
            curWorld.construct(1);
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
                
                this->curWorld.draw();
                this->player->draw();
            EndDrawing();
        }
};