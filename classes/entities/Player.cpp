#include <raylib.h>
#include <string>
#include <iostream>
#include "entities/Player.h"
#include "game/Consts.h"


Player::Player(int x, int y):
    width(32),
    height(32),
    spriteRec({0,0,this->width,height}),
    direction(1),
    // Player Values
    position({
        0,
        0,
        width * Consts::getScale(),
        height * Consts::getScale()
    }),
    speed(3),
    isMoving(0),
    // Animation
    frameDuration(4),
    frameTimer(0)
    {
        position.x = x;
        position.y = y;
    }

void Player::update(){
    callAnimation = "idle";
    move();
    animationControll();            
    animationUpdate();
}

void Player::draw(){
    spriteRec.width = width*direction;
    DrawTexturePro(
        curTexture, 
        spriteRec,
        position,
        (Vector2){width/2,height/2},
        0,
        WHITE
    );
    // DrawTextureRec(curTexture, spriteRec, position, WHITE);
}

//Private

void Player::move(){
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

void Player::animationUpdate(){
    if(++frameTimer == frameDuration){
        frameTimer = 0;
        if(++curFrame > frames){
            curFrame = 0;
        }
    }
    spriteRec.x = curFrame * spriteRec.width;
}

void Player::animationControll(){
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