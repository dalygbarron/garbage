#pragma once

#include "Entity.h"

/**
 * Like a character.
 */
class Dude: public Entity {
    public:
        virtual Action update(Game &game) override;

        virtual RenderParams getRenderParams() const override;
};