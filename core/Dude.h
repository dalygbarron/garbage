#pragma once

#include "Entity.h"

/**
 * Represents a thing that can move around in 3d space and do stuff.
 */
class Dude: public Entity {
    public:
        virtual Action update(Game const &game) override;

        virtual RenderParams getRenderParams() const override;
};