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
         * Plus operator with int.
         * @param rhs is the int to add to both components.
         * @return a new vector.
         */
        Vector operator+(int rhs) const;

        /**
         * minus operator.
         * @param rhs is the thing to subtract from this thing.
         * @return a new vector that is the subtraction.
         */
        Vector operator-(Vector const &rhs) const;

        /**
         * minus operator with int.
         * @param rhs is the int to subtract from both components.
         * @return a new vector.
         */
        Vector operator-(int rhs) const;

        /**
         * times operator.
         * @param rhs is the thing to multiply by.
         * @return this times rhs.
         */
        Vector operator*(Vector const &rhs) const;

        /**
         * times operator with int.
         * @param rhs is the int to multiply with both components.
         * @return a new vector.
         */
        Vector operator*(int rhs) const;

        /**
         * divided by operator.
         * @param rhs is the thing to divide by.
         * @return this divided by rhs.
         */
        Vector operator/(Vector const &rhs) const;

        /**
         * divided by operator with int.
         * @param rhs is the int to divide both components.
         * @return a new vector.
         */
        Vector operator/(int rhs) const;

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

        /**
         * Multiplication operator.
         * @param rhs is the vector to multiply this one by.
         * @return a reference to this.
         */
        Vector &operator*=(Vector const &rhs);

        /**
         * Division operator.
         * @param rhs is the vector to divide this one by.
         * @return a reference to this.
         */
        Vector &operator/=(Vector const &rhs);

        /**
         * Copy assignment operator.
         * @param rhs is the vector to copy.
         * @return a reference to this vector.
         */
        Vector &operator=(Vector const &rhs);
};