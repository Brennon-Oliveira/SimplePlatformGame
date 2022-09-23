#include <raylib.h>
#include <raymath.h>
#include <new>
#include "game/TextureLoader.h"
#include "entities/Player.h"
#include "world/World.h"
#include "game/Consts.h"
#include "game/Game.h"

Player* Game::player = new Player();
World* Game::curWorld = new World();

Game::Game(){
    InitWindow(Consts::getWidth(), Consts::getHeight(), Consts::getTitle());            
    ToggleFullscreen();
    SetTargetFPS(Consts::getFps());
    TextureLoader::loadTextures();
    Game::curWorld->construct(1);
    
    this->clock();
}

void Game::clock(){
    while (!WindowShouldClose())
    {
        this->update();
        this->draw();
    }
}

void Game::update(){
    float deltaTime = GetFrameTime();
    
    Game::player->update(deltaTime);
}

void Game::draw(){
    BeginDrawing();
        ClearBackground(WHITE);
        
        Game::curWorld->draw();
        Game::player->draw();
    EndDrawing();
}