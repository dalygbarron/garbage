#pragma once

/**
 * Stores and constructs message strings. The idea is that over the course of a
 * frame a message can be constructed of a number of different smaller messages
 * from various things happening. This will make better use of horizontal
 * screen space. Thus, we need to each frame take a number of strings
 * temporarily and then save them as a proper message when the new message is
 * accessed for the first time.
 * Message history will be saved but doesn't need to be unlimited, the last 64
 * messages or so is likely more than enough.
 */
class MessageStore {
    public:
        constexpr static char const *ERROR_MESSAGE = "ERROR";
        constexpr static char *EMPTY_MESSAGE = (char *)"";
        static int const N_MESSAGES = 64;
        static int const MESSAGE_BUFFER_SIZE = 512;

        /**
         * Initialises the store.
         */
        MessageStore();

        /**
         * Deletes allocated memory for messages.
         */
        ~MessageStore();

        /**
         * Tells you where the cursor is at, mostly for debug purposes.
         * @return the valued of the cursor.
         */
        int getCursor() const;

        /**
         * Gets an item based around which is most recent, with the most recent
         * one being 0. Obviously can't go N_MESSAGES or above.
         * @param index is the index of the message to get, from most recent.
         * @return a pointer to the message. Prone to dissappear so don't keep.
         */
        char const *operator[](int index) const;

        /**
         * Appends some text to the latest message along with a seperator.
         * @param text is the text to append.
         */
        void appendMessage(char const *text);

    private:
        mutable char messageBuffer[MESSAGE_BUFFER_SIZE];
        mutable char *messages[N_MESSAGES];
        mutable int cursor = 0;
        mutable int bufferCursor = 0;

        /**
         * Appends as much of a string as will fit to the message buffer.
         * @param string is the string to append.
         */
        void appendString(char const *string);
};