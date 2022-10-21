#pragma once

#include <unordered_map>
#include "Map.h"
#include "Action.h"
#include "Dude.h"

/**
 * Represents the overall game state.
 */
class Game {
    public:
        /**
         * Callback for when the player needs to provide input.
         * @param player is the player dude.
         */
        std::function<Action(Dude const &player)> playerInput = nullptr;

        /**
         * Callback for when the game wants to put a message on the game
         * console. Btw the string it sends is not permanent so save it.
         */
        std::function<void(char const *)> playerMessage = nullptr;

        /**
         * Load default game.
         */
        Game();

        /**
         * Load a saved game from the given file.
         * @param file is the name of the file.
         */
        Game(char const *file);

        /**
         * Start the game running. At this point you will only be able to
         * communicate via the provided callbacks and whatever return value
         * this function may have in the future.
         */
        void start();

        /**
         * Gives you a const ref to the current map.
         * @return const ref to the current map.
         */
        Map const &getCurrentMap() const;

        /**
         * Sends a message callback if the callback has been defined.
         * @param message is the message to send.
         */
        void sendMessage(char const *message) const;

    private:
        std::unordered_map<int, Map *> maps;
        int currentMap = 0;
};