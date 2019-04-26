#include "mod_wifi.h"
#include "data_pool.h"
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <unistd.h>

struct mod_wifi_type {
    /*! \brief Data structure that contains the info for the WiFi interface
     *  \attention To be used with constructor from ADT interface
     *
     */
    char *ifname;
    int sock;
    char *password;
    wapi_scan_info_t *hwinfotable; ///< This structure here will hold the info at level 2
};

PRIVATE void terminate(const char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

PUBLIC Mod_WiFi wifi_create(char *ifname) {
    Mod_WiFi wiFi = malloc(sizeof(struct mod_wifi_type));
    if (wiFi == NULL)
        terminate("Error module WiFi could not be created.");
    wiFi->hwinfotable = malloc(sizeof(struct wapi_scan_info_t));
    if (wiFi->hwinfotable == NULL)
        terminate("\nCouldn't allocate space for layer 2 info.");
    wiFi->password = malloc(IW_ESSID_MAX_SIZE * sizeof(char));
    if (wiFi->password == NULL)
        terminate("\nCan't allocate space for password.");
    wiFi->ifname = ifname; //Adesso puntano alla stessa stringa
    if (wifi_initialize(wiFi) < 0)
        terminate("\nCouldn't initialize WiFi data structure.");
    return wiFi;
}

PRIVATE bool wifi_initialize(Mod_WiFi module) {
    module->hwinfotable->next = NULL; //This is to disable for now multi-SSID support
    module->sock = wapi_make_socket();
    if (module->sock < 0)
        terminate("Couldn't initialize socket for IPC communication.");
    if (wapi_get_essid(module->sock, module->ifname, module->hwinfotable->essid, &module->hwinfotable->essid_flag) >=
        0)
        module->hwinfotable->has_essid = 1;
    if (wapi_get_mode(module->sock, module->ifname, &module->hwinfotable->mode) >= 0)
        module->hwinfotable->has_mode = 1;
    return module;
}

//PUBLIC bool wifi_change_ssid(Mod_WiFi module, unsigned char ssid) {
//    return false;
//}

PUBLIC bool wifi_change_password(Mod_WiFi module, unsigned char password) {
    return false;
}

PUBLIC Mod_WiFi wifi_destroy(Mod_WiFi module) {
    return false;
}

//Helper Methods


