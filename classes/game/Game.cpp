#include <raylib.h>
#include <raymath.h>
#include "entities/Player.h"
#include "world/World.h"
#include "game/Consts.h"
#include "game/Game.h"


Game::Game(){
    InitWindow(Consts::getWidth(), Consts::getHeight(), Consts::getTitle());            
    SetTargetFPS(Consts::getFps());
    curWorld.construct(1);
    this->player = new Player(30, 30);
    
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
    this->player->update();
}

void Game::draw(){
    BeginDrawing();
        ClearBackground(WHITE);
        
        this->curWorld.draw();
        this->player->draw();
    EndDrawing();
}