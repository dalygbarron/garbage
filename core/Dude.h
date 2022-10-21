#pragma once

#include "Entity.h"

/**
 * Represents a thing that can move around in 3d space and do stuff.
 */
class Dude: public Entity {
    public:
        /**
         * Updates the dude in accordance with his customs.
         * @param game is the game world which is used to make note of the
         *        surroundings and call callbacks if necessary.
         * @return the action they want to take.
         */
        virtual Action update(Game const &game);
};