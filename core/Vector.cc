#include "Vector.h"

Vector::Vector() {
    x = 0;
    y = 0;
}

Vector::Vector(int x, int y) {
    this->x = x;
    this->y = y;
}

Vector::~Vector() {}

Vector Vector::operator+(Vector const &rhs) const {
    return Vector(x + rhs.x, y + rhs.y);
}

Vector Vector::operator+(int rhs) const {
    return Vector(x + rhs, y + rhs);
}

Vector Vector::operator-(Vector const &rhs) const {
    return Vector(x - rhs.x, y - rhs.y);
}

Vector Vector::operator-(int rhs) const {
    return Vector(x - rhs, y - rhs);
}

Vector Vector::operator*(Vector const &rhs) const {
    return Vector(x * rhs.x, y * rhs.y);
}

Vector Vector::operator*(int rhs) const {
    return Vector(x * rhs, y * rhs);
}

Vector Vector::operator/(Vector const &rhs) const {
    return Vector(x / rhs.x, y / rhs.y);
}

Vector Vector::operator/(int rhs) const {
    return Vector(x / rhs, y / rhs);
}

Vector &Vector::operator+=(Vector const &rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
}

Vector &Vector::operator-=(Vector const &rhs) {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}

Vector &Vector::operator*=(Vector const &rhs) {
    x *= rhs.x;
    y *= rhs.y;
    return *this;
}

Vector &Vector::operator/=(Vector const &rhs) {
    x /= rhs.x;
    y /= rhs.y;
    return *this;
}

Vector &Vector::operator=(Vector const &rhs) {
    x = rhs.x;
    y = rhs.y;
    return *this;
}