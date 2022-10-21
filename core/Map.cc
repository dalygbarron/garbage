#include "Map.h"

Map::Map(Vector size): size(size) {
    this->tiles = new uint8_t[size.x * size.y * N_LAYERS];
}

Map::~Map() {
    delete[] this->tiles;
}

bool Map::inBounds(Vector pos, int layer) const {
    if (layer < 0 || layer >= N_LAYERS) return 0;
    if (pos.x < 0 || pos.y < 0 || pos.x >= size.x || pos.y >= size.y) return 0;
    return true;
}

uint8_t Map::getTile(Vector pos, int layer) const {
    if (!this->inBounds(pos, layer)) return 0;
    return tiles[layer * size.x * size.y + pos.y * size.x + pos.x];
}

void Map::setTile(Vector pos, int layer, uint8_t value) {
    if (!this->inBounds(pos, layer)) return;
    tiles[layer * size.x * size.y + pos.y * size.x + pos.x] = value;
}