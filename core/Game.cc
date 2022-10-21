#include "Game.h"

Game::Game() {
    Vector size(200, 200);
    Map *mainMap = new Map(size);
    mainMap->addEntity(new Dude());
    maps[currentMap] = mainMap;
}

Game::Game(char const *file): Game() {
    // TODO: doing nothing rn.
}

void Game::start() {
    while (true) {
        if (!maps[currentMap]->update(*this)) return;
    }
}

Map const &Game::getCurrentMap() const {
    return *(maps.at(currentMap));
}

void Game::sendMessage(char const *message) const {
    if (this->playerMessage) this->playerMessage(message);
}