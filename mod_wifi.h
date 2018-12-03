/*! \file
 *
 */
#ifndef MOD_WIFI_LIBRARY_H
#define MOD_WIFI_LIBRARY_H
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include "wapi.h"
#include "wireless.h"
#include "data_pool.h"

typedef struct mod_wifi_type * Mod_WiFi;

PUBLIC Mod_WiFi wifi_destroy(Mod_WiFi);
/*! \brief Constructor for the wifi module of the Connect Kit system
 *
 *  This will destroy the "object" provided with memory releasing and context destroying.
 *
 *  \return Free the Mod_WiFi created
 */

PUBLIC Mod_WiFi wifi_create();
/*! \brief Constructor for the wifi module of the Connect Kit system
 *
 *  This will create the wifi module ADT, will create a context to use within the libuci library
 *
 *  \return Mod_WiFi ADT not initialized
 */


PRIVATE bool wifi_initialize(Mod_WiFi module);
/*! \brief Constructor for the wifi module of the Connect Kit system
 *
 *  This will configure or reset the wifi module ADT, will load the configuration for the wifi module
 *
 *  \return Mod_WiFi ADT ready to use
 */

PUBLIC bool wifi_change_ssid(Mod_WiFi module, unsigned char ssid);
/*! \brief Setter of the
*
*  This will configure or reset the wifi module ADT
*
*  \return Mod_WiFi ADT ready to use
*/

PUBLIC bool wifi_change_password(Mod_WiFi module, unsigned char password);
/*! \brief Setter of the
*
*  This will configure or reset the wifi module ADT
*
*  \return Mod_WiFi ADT ready to use
*/
#endif