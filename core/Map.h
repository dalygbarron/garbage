#pragma once

#include <stdint.h>
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
         * Checks if a given location is within the bounds of this map.
         * @param pos is the position within the layer.
         * @param layer is the layer.
         * @return true if this location is in the map and false otherwise.
         */
        bool inBounds(Vector pos, int layer) const;

        /**
         * Gets the map tile at the given location.
         * @param pos is the location in the map. If the location is not in the
         *        map then 0 will be returned always.
         * @param layer is the layer the tile is on.
         * @return the tile code.
         */
        uint8_t getTile(Vector pos, int layer) const;

        /**
         * Sets the value of the tile at the given point on the given layer.
         * @param pos is the location in the layer to set.
         * @param layer is the layer on which to set the tile.
         * @param value is the value to give to the tile.
         */
        void setTile(Vector pos, int layer, uint8_t value);

    private:
        uint8_t *tiles;
};