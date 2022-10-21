#include "Util.h"
#include <cstdarg>
#include <stdio.h>

static char tempBuffer[Util::BUFFER_LENGTH];

char const *Util::tprintf(char const *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vsnprintf(tempBuffer, BUFFER_LENGTH, fmt, args);
    va_end(args);
    return tempBuffer;
}

int Util::wrap(int value, int in) {
    int result = value % in;
    if (result >= 0) return result;
    return in + result;
}