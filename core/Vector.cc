#include "Vector.h"

Vector::Vector() {
    this->x = 0;
    this->y = 0;
}

Vector::Vector(int x, int y) {
    this->x = x;
    this->y = y;
}

Vector::~Vector() {}

Vector Vector::operator+(Vector const &rhs) const {
    return Vector(this->x + rhs.x, this->y + rhs.y);
}

Vector Vector::operator-(Vector const &rhs) const {
    return Vector(this->x - rhs.x, this->y - rhs.y);
}

Vector &Vector::operator+=(Vector const &rhs) {
    this->x += rhs.x;
    this->y += rhs.y;
    return *this;
}

Vector &Vector::operator-=(Vector const &rhs) {
    this->x -= rhs.x;
    this->y -= rhs.y;
}