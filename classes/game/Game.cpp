#include <raylib.h>
#include <raymath.h>
#define MAX(a, b) ((a)>(b)? (a) : (b))
#define MIN(a, b) ((a)<(b)? (a) : (b))

#include "../../classes/entities/player/Player.cpp"

class Game {
    public:

        const int WIDTH = 500;
        const int HEIGHT = 500;
        const int FPS = 60;
        Player* player;
        RenderTexture2D target;

        Game(){
            InitWindow(this->WIDTH, this->HEIGHT, "Simple Platform Game");            
            SetTargetFPS(this->FPS);
            target = LoadRenderTexture(WIDTH, HEIGHT);
            SetTextureFilter(target.texture, 2);
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
            float scale = MIN((float)GetScreenWidth()/WIDTH, (float)GetScreenHeight()/HEIGHT);

            BeginTextureMode(target);
                ClearBackground(WHITE);

                this->player->draw();
            EndTextureMode();
            BeginDrawing();
                ClearBackground(WHITE);
                
                DrawTexturePro(
                    target.texture,
                    (Rectangle){0,0, (float)target.texture.width, (float)target.texture.height},
                    (Rectangle){ (GetScreenWidth() - ((float)WIDTH*scale))*0.5f, (GetScreenHeight() - ((float)HEIGHT*scale))*0.5f,
                    (float)WIDTH*scale, (float)HEIGHT*scale }, (Vector2){ 0, 0 }, 0.0f, WHITE
                );
            EndDrawing();
        }
};