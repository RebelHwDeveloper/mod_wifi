//
// Created by andi on 11/12/18.
//

#ifndef MOD_WIFI_DATA_POOL_H
#define MOD_WIFI_DATA_POOL_H

#define UCI_ASSERT(ctx, expr) do {	\
    if (!(expr)) {			\
    perror("[%s:%d] Assertion failed\n", __FILE__, __LINE__); \
    }				\
    } while (0)

#define PUBLIC /* none */
#define PRIVATE static
#define MAX_LEN_PW 16

bool validate_str(const unsigned char *str, bool name) {
    if (!*str)
        return false;
    while (*str) {
        unsigned char c = *str;
        if (!isalnum(c) && c != '_') {
            if (name || (c < 33) || (c > 126))
                return false;
        }
        str++;
    }
    return true;
}

bool uci_validate_text(const unsigned char *str) {
    while (*str) {
        unsigned char c = *str;
        if ((c == '\r') || (c == '\n') ||
            ((c < 32) && (c != '\t')))
            return false;
        str++;
    }
    return true;
}

#endif //MOD_WIFI_DATA_POOL_H
