#pragma once

#include "Vector.h"

class Action {
    public:
        enum class Type {
            MOVE,
            QUIT
        } type;
        Vector pos;
        void *target = nullptr;

        /**
         * Default constructor.
         */
        Action();

        /**
         * Constructor that lets you specify type. Useful for making a quit
         * action or something in a single line.
         * @param type is the type this action has.
         */
        Action(Type type);
};