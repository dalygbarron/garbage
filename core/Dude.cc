#include "Dude.h"
#include "Game.h"
#include "Util.h"

Action Dude::update(Game const &game) {
    if (rand() % 6 == 3) {
        game.sendMessage(Util::tprintf(
            "Extreme aids episode number %d",
            rand() % 99999999999
        ));
    }
    return game.playerInput(*this);
}