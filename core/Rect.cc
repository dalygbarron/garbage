#include "Rect.h"

Rect::Rect() {}

Rect::Rect(Vector pos, Vector size): pos(pos), size(size) {}

bool Rect::contains(Vector location) {
    return location.x >= pos.x && location.y >= pos.y &&
        location.x <= pos.x + size.x && location.y <= pos.y + size.y;
}