#pragma once
#include <raylib.h>
#include <string>
#include <iostream>

class Player{
    protected:
        // Graphics
        float width;
        float height;
        Rectangle spriteRec;
        int direction;

        // Player Values
        Rectangle position;
        float speed;
        float jumpHeight;
        float mass;
        int isMoving;
        int canJump;
        int isJumping;

        // Animation
        const int frameDuration;
        float frameTimer;
        int frames;
        int curFrame;
        std::string lastAnimation;
        std::string callAnimation;
        
        // sprite
        Texture2D curTexture;

    public:
        Player();

        void update(float delta);

        void draw();

        void setPosition(int x, int y);

        int getWidth();

        int getHeight();
    private:

        void move(float delta);

        // void gravity(int delta);

        void animationUpdate(float delta);

        void animationControll();
};