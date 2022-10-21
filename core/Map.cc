#include "Map.h"

Map::Map(Vector size): size(size) {
    tiles = new uint8_t[size.x * size.y * N_LAYERS];
    for (int x = 0; x < size.x; x++) {
        for (int y = 0; y < size.y; y++) {
            setTile(Vector(x, y), 0, 44 + rand() % 5);
        }
    }
    printf("(s %d %d)", size.x, size.y);
}

Map::~Map() {
    delete[] tiles;
}

bool Map::update(Game const &game) {
    for (Entity *entity: entities) {
        Action a = entity->update(game);
        if (a.type == Action::Type::QUIT) return false;
        else if (a.type == Action::Type::MOVE) {
            // TODO: handle attacks.
            entity->pos += a.pos;
        }
    }
    return true;
}

bool Map::inBounds(Vector pos, int layer) const {
    if (layer < 0 || layer >= N_LAYERS) return 0;
    if (pos.x < 0 || pos.y < 0 || pos.x >= size.x || pos.y >= size.y) return 0;
    return true;
}

uint8_t Map::getTile(Vector pos, int layer) const {
    if (!inBounds(pos, layer)) return 0;
    return tiles[layer * size.x * size.y + pos.y * size.x + pos.x];
}

void Map::setTile(Vector pos, int layer, uint8_t value) {
    if (!inBounds(pos, layer)) return;
    tiles[layer * size.x * size.y + pos.y * size.x + pos.x] = value;
}

void Map::addEntity(Entity *entity) {
    entities.push_back(entity);
}