#pragma once

/**
 * Representation of how some stuff should be drawn.
*/
class RenderParams {
    public:
        char c;
        enum class Colour {
            RED,
            GREEN,
            BLUE,
            CYAN,
            WHITE,
            MAGENTA,
            YELLOW
        } colour;
        enum class Effect {
            NONE,
            BURNING,
            FROZEN,
            GLOWING
        } effect;

        /**
         * default constructor.
         */
        RenderParams();

        /**
         * Sets all the parameters.
         * @param c is the character which can either represent an actual
         *        character to draw on screen or just a class of image or
         *        whatever.
         * @param colour is the colour to draw the thing with.
         * @param effect is an effect to draw on the things.
        */
        RenderParams(char c, Colour colour, Effect effect);
};