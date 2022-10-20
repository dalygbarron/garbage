#pragma once

#include "Vector.h"

/**
 * Your usual level type thing. Stores a grid of ground tiles and a grid of wall
 * tiles, then stores thingies that exist upon that grid like characters and
 * items and shiet.
 */
class Map {
    public:
        static int const N_LAYERS = 3;
        Vector const size;

        /**
         * creates the map and it's tile data.
         * @param size is the width and height of the map.
         */
        Map(Vector size);

        /**
         * deletes the map and it's tile data.
         */
        ~Map();

        /**
         * Gets the map tile at the given location.
         * @param pos is the location in the map. If the location is not in the
         *        map then 0 will be returned always.
         * @param layer is the layer the tile is on.
         * @return the tile code.
         */
        char getTile(Vector pos, int layer) const;

    private:
        char *tiles;
};