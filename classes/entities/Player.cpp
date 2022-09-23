#include <raylib.h>
#include <iostream>
#include <string>
#include "entities/Player.h"
#include "game/Consts.h"


Player::Player():
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
    speed(300),
    isMoving(0),
    // Animation
    frameDuration(4),
    frameTimer(0)
    { }

void Player::update(float delta){
    callAnimation = "idle";
    move(delta);
    animationControll();            
    animationUpdate(delta);
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

void Player::move(float delta){
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
    position.x += speed * direction * isMoving * delta;
    // std::cout << delta << "\n";
    // std::cout << "\nx: " << position.x << " - y: " << position.y;
}

void Player::animationUpdate(float delta){
    std::cout << frameTimer << "\n";
    if((frameTimer+=delta*75) >= frameDuration){
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

void Player::setPosition(int x, int y){
    position.x = x;
    position.y = y;
}

int Player::getWidth(){
    return width;
}

int Player::getHeight(){
    return height;
}