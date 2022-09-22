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
        int speed;
        int isMoving;

        // Animation
        const int frameDuration;
        int frameTimer;
        int frames;
        int curFrame;
        std::string lastAnimation;
        std::string callAnimation;
        
        // sprite
        Texture2D curTexture;

    public:
        Player(int x, int y);

        void update();

        void draw();
    private:

        void move();

        void animationUpdate();

        void animationControll();
};