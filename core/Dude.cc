#include "Dude.h"
#include "Game.h"
#include "Util.h"

Action Dude::update(Game const &game) {
    if (rand() % 6 == 3) {
        game.sendMessage(Util::tprintf(
            "Extreme aids wahoooooooooooooooo baby episode number %d",
            rand() % 99999999999
        ));
    }
    return game.playerInput(*this);
}

RenderParams Dude::getRenderParams() const {
    return RenderParams(
        'g',
        RenderParams::Colour::RED,
        RenderParams::Effect::NONE
    );
}