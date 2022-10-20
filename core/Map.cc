#include "Map.h"

Map::Map(int width, int height):
    width(width), height(height)
{
    this->tiles = new char[width * height * N_LAYERS];
}

Map::~Map() {
    delete[] this->tiles;
}