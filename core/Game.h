#pragma once

#include "Map.h"

/**
 * Represents the overall game state.
 */
class Game {
    public:
        static int const N_MAPS = 50;

    private:
        Map maps[N_MAPS];
        int currentMap = 0;
};