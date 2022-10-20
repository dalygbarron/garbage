#include "Map.h"

Map::Map(Vector size): size(size) {
    this->tiles = new char[size.x * size.y * N_LAYERS];
}

Map::~Map() {
    delete[] this->tiles;
}

char Map::getTile(Vector pos, int layer) const {
    if (layer < 0 || layer >= N_LAYERS) return 0;
    if (pos.x < 0 || pos.y < 0 || pos.x >= size.x || pos.y >= size.y) return 0;
    return tiles[layer * size.x * size.y + pos.y * size.x + pos.x];
}
