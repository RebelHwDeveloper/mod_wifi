#include "mod_wifi.h"
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <unistd.h>

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
    char *password;
    wapi_route_info_t addrtable;
    wapi_scan_info_t hwinfotable;
};

PRIVATE void terminate(const char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

PUBLIC Mod_WiFi wifi_create() {
    //Devo istanziare la mia ADT che rappresenta l'interfaccia WiFi
    Mod_WiFi module = (Mod_WiFi) malloc(sizeof(struct mod_wifi_type));
    if (module == NULL)
        terminate("Error! memory not allocated.");
    //Inizio con la parte di routing wapi_route_info_t
    memset(module->addrtable.next, 0, sizeof(struct in_addr)); //Supporto per lo "strict_routing" TCP
    memset(&(module->addrtable.dest), 0, sizeof(struct in_addr)); //Supporto per il collegamento PPP WDS
    struct ifreq ifr;
    int sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_IP);
    if (sock < 0) {
        free(module);
        terminate("Couldn't get interface flags.");
    }
    memset(&ifr, 0, sizeof(ifr));
    if (ioctl(sock, SIOCGIFFLAGS, &ifr) < 0) {
        perror("SIOCGIFFLAGS");
    }
    if (shutdown(sock, SHUT_RDWR) < 0) // secondly, terminate the 'reliable' delivery
        if (errno != ENOTCONN && errno != EINVAL) // SGI causes EINVAL
            perror("shutdown");
    if (close(sock) < 0) // finally call close()
        perror("close");
    module->addrtable.flags = (unsigned int) ifr.ifr_ifru.ifru_flags;
    module->addrtable.mtu = 0;
    module->addrtable.refcnt = 0;
    module->addrtable.use = 0;
    memset(&(module->addrtable.netmask), 0, sizeof(struct in_addr));
    module->addrtable.window = 0;
    module->addrtable.irtt = 0;
    wapi_list_t list;
    bzero(&list, sizeof(wapi_list_t));
    if (wapi_get_ifnames(&list) >= 0) {
        int count = 0;
        wapi_string_t *str;
        str = list.head.string;
        do {
            count++;
            str = str->next;
        } while (str != NULL);
        if (count != 1)
            terminate("Only one wireless interface supported");
        module->addrtable.ifname = str->data;
        printf("Nome dell'interfaccia: %s", module->addrtable.ifname);
    }

    return NULL;
}

PRIVATE bool wifi_initialize(Mod_WiFi module) {
    return false;
}

PUBLIC bool wifi_change_ssid(Mod_WiFi module, unsigned char ssid) {
    return false;
}

PUBLIC bool wifi_change_password(Mod_WiFi module, unsigned char password) {
    return false;
}

PUBLIC Mod_WiFi wifi_destroy(Mod_WiFi module) {
    return false;
}



