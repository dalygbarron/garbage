#include "RenderParams.h"

RenderParams::RenderParams() {}

RenderParams::RenderParams(char c, Colour colour, Effect effect) {
    this->c = c;
    this->colour = colour;
    this->effect = effect;
}