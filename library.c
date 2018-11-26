#include "library.h"
#include "../uci-master/libuci.c"

void hello(void) {
    printf("Hello, World!\n");
}

PRIVATE struct mod_wifi_type {
    /*! \brief Data structure that contains the info for the WiFi interface
     *
     *  I preferred for the sake of readability to avoid using functions and void* type pointer to try force generic
     *  programming in C, albeit possible and much more OO, the code was really unreadable and cleaned it up resorting
     *  to more student-like ADTs.
     */
    unsigned char password[MAX_LEN_PW];
    unsigned char ssid[MAX_LEN_PW];
};

PRIVATE void terminate(const char* message){
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

PUBLIC Mod_WiFi wifi_create(){
    
    return false;
}

PRIVATE bool wifi_initialize(Mod_WiFi module){
    return false;
}

PUBLIC bool wifi_change_ssid(Mod_WiFi module, unsigned char ssid){
    return false;
}

PUBLIC bool wifi_change_password(Mod_WiFi module, unsigned char password){
    return false;
}

PUBLIC Mod_WiFi wifi_destroy(Mod_WiFi module){
    return false;
}



