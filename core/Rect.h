#pragma once

#include "Vector.h"

class Rect {
    public:
        Vector pos;
        Vector size;

        /**
         * Creates a default rect with no position or size.
         */
        Rect();

        /**
         * Creates a rect based on a position of top left corner and size.
         * @param pos is the position of the top left corner.
         * @param size is the extent to which it protrudes from there.
         */
        Rect(Vector pos, Vector size);

        /**
         * tells you if the rect contains the given point.
         * @param location is the location to check for.
         * @return true iff it is in the rect.
         */
        bool contains(Vector location);
};