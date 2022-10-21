#pragma once

/**
 * Namespace where I stick utility stuff that doesn't go anywhere else.
 */
namespace Util {
    static const unsigned int BUFFER_LENGTH = 256;

    /**
     * Like printf but it writes a static buffer that will temporarily hold the
     * data. Just make sure that before you call tprintf again you have already
     * saved the string somewhere else if you need to do so. Also, the string
     * has a maximum length since it is written in a buffer.
     * @param fmt is the format string.
     * @param ... is the things to stick in the format string.
    */
    char const *tprintf(char const *fmt, ...);

    /**
     * Takes a value and wraps it between [0, in). Like so if
     * value is -1 it will become in - 1, and if it's in it will become 0 etc.
     * @param value is the value to wrap.
     * @param in is the value to wrap it in.
     * @return the wrapped version.
    */
    int wrap(int value, int in);
};