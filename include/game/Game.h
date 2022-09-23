#pragma once
#include <raylib.h>
#include <raymath.h>
#include "entities/Player.h"
#include "world/World.h"

class Game {
    public:

        static Player* player;
        static World* curWorld;

        Game();

    private:
        void clock();

        void update();

        void draw();
};