#pragma once

/**
 * Your usual level type thing. Stores a grid of ground tiles and a grid of wall
 * tiles, then stores thingies that exist upon that grid like characters and
 * items and shiet.
 */
class Map {
    public:
        static int const N_LAYERS = 3;
        int const width;
        int const height;

        /**
         * creates the map and it's tile data.
         * @param width is the width of the map.
         * @param height is the height of the map.
         */
        Map(int width, int height);

        /**
         * deletes the map and it's tile data.
         */
        ~Map();

    private:
        char *tiles;
};