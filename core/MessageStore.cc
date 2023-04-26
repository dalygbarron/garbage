#include "MessageStore.h"
#include <stdio.h>
#include <string.h>

MessageStore::MessageStore() {
    for (int i = 0; i < N_MESSAGES; i++) {
        messages[i] = EMPTY_MESSAGE;
    }
}

MessageStore::~MessageStore() {
    for (int i = 0; i < N_MESSAGES; i++) {
        if (messages[i] != EMPTY_MESSAGE) delete[] messages[i];
    }
}

int MessageStore::getCursor() const {
    return bufferCursor;
}

char const *MessageStore::operator[](int index) const {
    if (bufferCursor != 0) {
        cursor++;
        if (cursor == N_MESSAGES) cursor = 0;
        if (messages[cursor] != EMPTY_MESSAGE) delete[] messages[cursor];
        messages[cursor] = new char[bufferCursor + 1];
        strncpy(messages[cursor], messageBuffer, bufferCursor);
        messages[cursor][bufferCursor] = 0;
        bufferCursor = 0;
    }
    if (index < 0 || index >= N_MESSAGES) {
        return ERROR_MESSAGE;
    }
    int relative = cursor - index;
    if (relative < 0) relative += N_MESSAGES;
    return messages[relative];
}

void MessageStore::appendMessage(char const *text) {
    if (bufferCursor != 0) appendString(" - ");
    appendString(text);
}

void MessageStore::appendString(char const *string) {
    for (int i = 0; i < MESSAGE_BUFFER_SIZE - bufferCursor; i++) {
        char c = string[i];
        if (c == 0) return;
        messageBuffer[bufferCursor] = c;
        bufferCursor++;
    }
}