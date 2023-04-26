#pragma once

#include "Vector.h"
#include "Action.h"
#include "RenderParams.h"

// forward declaration
class Game;

/**
 * A thing that exists within the space of a map and can move around.
 */
class Entity {
    public:
        Vector pos;

        /**
         * Virtual destructor is mandatory or something or nothing.
         */
        virtual ~Entity();

        /**
         * Updates the entity.
         * @param game is the game which is used for callbacks and shiet.
         * @return the action the entity wants to take.
         */
        virtual Action update(Game &game) = 0;

        /**
         * Tells you how this entity wants to be rendered.
         * @return render params telling all.
         */
        virtual RenderParams getRenderParams() const = 0;
};