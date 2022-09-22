#pragma once
#include <raylib.h>
#include <raymath.h>
#include "entities/Player.h"
#include "world/World.h"

class Game {
    public:

        Player* player;
        World curWorld;

        Game();

    private:
        void clock();

        void update();

        void draw();
};