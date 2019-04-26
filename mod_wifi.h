/*! \file mod_wifi.h
    \brief Principal interface file

    Here you'll find the declarations of all the structures and functions used, see main page for explanation in usage.
    This is the first of a set of specializations of various network interfaces, generic, ppp, slip...
    I'll use it just with a reference, not with a full-fledged inheritance system. I'll give a pointer to which the
    generic network interface can hook and use. This respects the coupling-cohesion pattern through information hiding.
*/
#ifndef MOD_WIFI_LIBRARY_H
#define MOD_WIFI_LIBRARY_H

#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "../wapi/wapi.h"

#define PUBLIC /* none */
#define PRIVATE static


typedef struct mod_wifi_type *Mod_WiFi;

PUBLIC Mod_WiFi wifi_destroy(Mod_WiFi);
/*! \brief Constructor for the wifi module of the Connect Kit system
 *
 *  This will destroy the "object" provided with memory releasing and context destroying.
 *
 *  \return Free the Mod_WiFi created
 */

PUBLIC Mod_WiFi wifi_create(char* ifname /**< [in] interface to create .*/);
/*! \brief Constructor for the wifi module of the Connect Kit system
 *  This will create the wifi module ADT, it will allocate memory that will be used to hold info populated by the
 *  instantiation function `wifi_initialize()`.
 *  \attention It does not do parameter checking, so use carefully
 *
 *  \return Mod_WiFi ADT not initialized
 */


PRIVATE bool wifi_initialize(Mod_WiFi module);
/*! \brief Constructor for the wifi module of the Connect Kit system
 *
 *  This will configure or reset the wifi module ADT, will load the configuration for the wifi module from the
 *
 *  \return Mod_WiFi ADT ready to use
 */

//todo:Controllo errori per parametri in ignresso
PUBLIC bool wifi_change_ssid(Mod_WiFi module, unsigned char *interface /**< [in] interface to change SSID .*/);
/*! \brief Setter of wifi
*
*  This will set (change) the SSID of the wireless interface.
*
*
*  \return Success or failure of the operation
*/

PUBLIC bool wifi_get_ssid(Mod_WiFi module, unsigned char *ssid_out /**< [out] data output of function*/);
/*! \brief Getter of wifi
*
*  This function gives in output the SSID of the network, it was intended for a complete ESSID so it
*  should be connected to a distribution network to form an ESS. The returned value is not the SSID!
*  It's the result operation success or failure, so if you get return false you should not trust the
*  output of the function, beacuse an error may have silently slipped and you're using stale values.
*
*  \return Success failure of operation
*/

PUBLIC bool wifi_change_password(Mod_WiFi module, unsigned char password);
/*! \brief Setter of the
*
*  This will set (change) the SSID of the wireless interface.
*
*  \return Success failure of operation
*/
#endif