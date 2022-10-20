#pragma once

/**
 * Very basic int vector class. Doesn't have any vector math functions because
 * they're pretty much useless with ints and I only really need this class to
 * store positions and sizes.
 */
class Vector {
    public:
        int x;
        int y;

        /**
         * Default constructor makes all values 0.
         */
        Vector();

        /**
         * Constructor to set both values.
         */
        Vector(int x, int y);

        /**
         * Destructor does nothing but it's required I think.
         */
        ~Vector();

        /**
         * plus operator.
         * @param rhs is the thing to add to this thing.
         * @return a new vector that is the addition of this and the other.
         */
        Vector operator+(Vector const &rhs) const;

        /**
         * minus operator.
         * @param rhs is the thing to subtract from this thing.
         * @return a new vector that is the subtraction.
         */
        Vector operator-(Vector const &rhs) const;

        /**
         * add operator.
         * @param rhs is the vector to add to this one.
         * @return a reference to this vector.
         */
        Vector &operator+=(Vector const &rhs);

        /**
         * Subtract operator.
         * @param rhs is the thing to subtract from this one.
         * @return a reference to this vector.
         */
        Vector &operator-=(Vector const &rhs);
};