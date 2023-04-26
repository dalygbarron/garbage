#include "Dude.h"
#include "Game.h"
#include "Util.h"

Action Dude::update(Game &game) {
    for (int i = 0; i < 5; i++) {
        if (rand() % 6 == 3) {
            game.messageStore.appendMessage(Util::tprintf(
                "Extreme aids wahoooooooooooooooo baby episode number %d",
                rand() % 99999999999
            ));
        } else {
            break;
        }
    }
    
    if (game.playerInput) return game.playerInput(*this);
    return Action();
}

RenderParams Dude::getRenderParams() const {
    return RenderParams(
        '@',
        RenderParams::Colour::RED,
        RenderParams::Effect::NONE
    );
}