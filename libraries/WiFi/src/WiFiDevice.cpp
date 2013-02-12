/*
 * WifiDevice.cpp
 *
 *  Created on: 05.03.2012
 *      Author: Kaarel
 */

#include "WifiDevice.h"

// Strings stored in Program space
prog_char s_WIFLYDEVICE_LIBRARY_VERSION[] PROGMEM = "WiFlySerial v1.03";
prog_char s_WIFLYDEVICE_JOIN[] PROGMEM = "join ";
prog_char s_WIFLYDEVICE_OPEN[] PROGMEM = "open ";
prog_char s_WIFLYDEVICE_CLOSE[] PROGMEM = "close ";
prog_char s_WIFLYDEVICE_ASSOCIATED[] PROGMEM = "ssociated";
prog_char s_WIFLYDEVICE_ATTN[] PROGMEM = "$$$";
prog_char s_WIFLYDEVICE_VER[] PROGMEM ="ver";
prog_char s_WIFLYDEVICE_LEAVE_CMD_MODE[] PROGMEM ="exit";
prog_char s_WIFLYDEVICE_REBOOT[] PROGMEM ="reboot";
prog_char s_WIFLYDEVICE_SAVE[] PROGMEM ="save";
prog_char s_WIFLYDEVICE_GET_MAC[] PROGMEM =" get mac";
prog_char s_WIFLYDEVICE_GET_MAC_ADDR[] PROGMEM ="Addr=";
prog_char s_WIFLYDEVICE_GET_IP[] PROGMEM =" get ip";
prog_char s_WIFLYDEVICE_GET_GW[] PROGMEM = " ";// "GW=";
prog_char s_WIFLYDEVICE_GET_NM[] PROGMEM = " ";// "NM=";
prog_char s_WIFLYDEVICE_LEAVE[] PROGMEM ="leave";
prog_char s_WIFLYDEVICE_SET_SSID[] PROGMEM =" set wlan s ";
prog_char s_WIFLYDEVICE_SET_CHANNEL[] PROGMEM =" set wlan c ";
prog_char s_WIFLYDEVICE_SET_WIFI_AUTH[] PROGMEM =" set wlan a ";
prog_char s_WIFLYDEVICE_SET_WIFI_JOIN[] PROGMEM =" set wlan j ";
prog_char s_WIFLYDEVICE_SET_PASSPHRASE[] PROGMEM =" set w p ";
prog_char s_WIFLYDEVICE_NETWORK_SCAN[] PROGMEM ="scan ";
prog_char s_WIFLYDEVICE_AOK[] PROGMEM ="";
prog_char s_WIFLYDEVICE_SET_UART_BAUD[] PROGMEM ="set u b 9600 ";
prog_char s_WIFLYDEVICE_DEAUTH[] PROGMEM ="Deauth";
prog_char s_WIFLYDEVICE_SET_NTP[] PROGMEM =" set time a ";
prog_char s_WIFLYDEVICE_SET_NTP_ENABLE[] PROGMEM ="set time e ";
prog_char s_WIFLYDEVICE_SET_DEVICEID[] PROGMEM ="set opt deviceid ";
prog_char s_WIFLYDEVICE_IP_DETAILS[] PROGMEM ="get ip";
prog_char s_WIFLYDEVICE_GET_DNS_DETAILS[] PROGMEM ="get dns";
prog_char s_WIFLYDEVICE_GET_TIME[] PROGMEM ="show t t";
prog_char s_WIFLYDEVICE_SET_DHCP[] PROGMEM ="set ip dhcp ";
prog_char s_WIFLYDEVICE_SET_IP[] PROGMEM ="set ip a ";
prog_char s_WIFLYDEVICE_SET_NETMASK[] PROGMEM ="set ip n ";
prog_char s_WIFLYDEVICE_SET_GATEWAY[] PROGMEM ="set ip g ";
prog_char s_WIFLYDEVICE_SET_DNS[] PROGMEM ="set dns addr ";
prog_char s_WIFLYDEVICE_SET_LOCAL_PORT[] PROGMEM ="set ip local ";
prog_char s_WIFLYDEVICE_SET_REMOTE_PORT[] PROGMEM ="set ip remote  ";
prog_char s_WIFLYDEVICE_SET_PROTOCOL[] PROGMEM ="set ip proto ";
prog_char s_WIFLYDEVICE_ERR_REBOOOT[] PROGMEM ="Attempting reboot";
prog_char s_WIFLYDEVICE_ERR_START_FAIL[] PROGMEM ="Failed to get cmd prompt:Halted.";
prog_char s_WIFLYDEVICE_SET_UART_MODE[] PROGMEM ="set u m 1 ";
prog_char s_WIFLYDEVICE_GET_WLAN[] PROGMEM ="get wlan ";
prog_char s_WIFLYDEVICE_GET_RSSI[] PROGMEM ="show rssi ";
prog_char s_WIFLYDEVICE_GET_BATTERY[] PROGMEM ="show batt ";
prog_char s_WIFLYDEVICE_GET_STATUS[] PROGMEM ="show conn ";
prog_char s_WIFLYDEVICE_RETURN[] PROGMEM ="\r";
prog_char s_WIFLYDEVICE_GET_IP_IND[] PROGMEM ="IP=";
prog_char s_WIFLYDEVICE_GET_NM_IND[] PROGMEM ="NM=";
prog_char s_WIFLYDEVICE_GET_GW_IND[] PROGMEM ="GW=";
prog_char s_WIFLYDEVICE_GET_DNS_IND[] PROGMEM ="DNS=";
prog_char s_WIFLYDEVICE_GET_WLAN_SSID_IND[] PROGMEM ="SSID=";
prog_char s_WIFLYDEVICE_GET_RSSI_IND[] PROGMEM ="RSSI=";
prog_char s_WIFLYDEVICE_GET_WLAN_DEV_IND[] PROGMEM ="DeviceID=";
prog_char s_WIFLYDEVICE_GET_BATTERY_IND[] PROGMEM ="Batt=";
prog_char s_WIFLYDEVICE_GET_TIME_IND[] PROGMEM ="RTC=";
prog_char s_WIFLYDEVICE_GET_STATUS_IND[] PROGMEM ="8";
prog_char s_WIFLYDEVICE_GET_IP_UP_IND[] PROGMEM ="F=";

// Index of strings
#define STI_WIFLYDEVICE_INDEX_JOIN        0
#define STI_WIFLYDEVICE_INDEX_ASSOCIATED  1
#define STI_WIFLYDEVICE_ATTN              2
#define STI_WIFLYDEVICE_VER               3
#define STI_WIFLYDEVICE_GET_MAC           4
#define STI_WIFLYDEVICE_GET_IP            5
#define STI_WIFLYDEVICE_GET_GW            6
#define STI_WIFLYDEVICE_GET_NM            7
#define STI_WIFLYDEVICE_LEAVE             8
#define STI_WIFLYDEVICE_SET_SSID          9
#define STI_WIFLYDEVICE_SET_PASSPHRASE    10
#define STI_WIFLYDEVICE_NETWORK_SCAN      11
#define STI_WIFLYDEVICE_AOK               12
#define STI_WIFLYDEVICE_SET_UART_BAUD     13
#define STI_WIFLYDEVICE_DEAUTH            14
#define STI_WIFLYDEVICE_SET_NTP           15
#define STI_WIFLYDEVICE_SET_NTP_ENABLE    16
#define STI_WIFLYDEVICE_SET_DEVICEID      17
#define STI_WIFLYDEVICE_GET_IP_DETAILS    18
#define STI_WIFLYDEVICE_LEAVE_CMD_MODE    19
#define STI_WIFLYDEVICE_GET_DNS_DETAILS   20
#define STI_WIFLYDEVICE_GET_TIME          21
#define STI_WIFLYDEVICE_SET_DHCP          22
#define STI_WIFLYDEVICE_SET_IP            23
#define STI_WIFLYDEVICE_SET_NETMASK       24
#define STI_WIFLYDEVICE_SET_GATEWAY       25
#define STI_WIFLYDEVICE_SET_DNS           26
#define STI_WIFLYDEVICE_ERR_REBOOT        27
#define STI_WIFLYDEVICE_ERR_START_FAIL    28
#define STI_WIFLYDEVICE_SET_UART_MODE     29
#define STI_WIFLYDEVICE_GET_WLAN          30
#define STI_WIFLYDEVICE_GET_RSSI          31
#define STI_WIFLYDEVICE_GET_BATTERY       32
#define STI_WIFLYDEVICE_LIBRARY_VERSION   33
#define STI_WIFLYDEVICE_SET_CHANNEL       34
#define STI_WIFLYDEVICE_SET_WIFI_AUTH     35
#define STI_WIFLYDEVICE_SET_WIFI_JOIN     36
#define STI_WIFLYDEVICE_GET_STATUS        37
#define STI_WIFLYDEVICE_GET_MAC_ADDR      38
#define STI_WIFLYDEVICE_RETURN            39
#define STI_WIFLYDEVICE_GET_IP_IND        40
#define STI_WIFLYDEVICE_GET_NM_IND        41
#define STI_WIFLYDEVICE_GET_GW_IND        42
#define STI_WIFLYDEVICE_GET_DNS_IND       43
#define STI_WIFLYDEVICE_GET_WLAN_SSID_IND 44
#define STI_WIFLYDEVICE_GET_RSSI_IND      45
#define STI_WIFLYDEVICE_GET_BATTERY_IND   46
#define STI_WIFLYDEVICE_GET_WLAN_DEV_IND  47
#define STI_WIFLYDEVICE_GET_TIME_IND      48
#define STI_WIFLYDEVICE_GET_STATUS_IND    49
#define STI_WIFLYDEVICE_GET_IP_UP_IND     50
#define STI_WIFLYDEVICE_OPEN              51
#define STI_WIFLYDEVICE_REBOOT            52
#define STI_WIFLYDEVICE_CLOSE             53
#define STI_WIFLYDEVICE_SET_LOCAL_PORT    54
#define STI_WIFLYDEVICE_SET_REMOTE_PORT   55
#define STI_WIFLYDEVICE_SET_PROTOCOL      56
#define STI_WIFLYDEVICE_SAVE              57

// String Table in Program space
PROGMEM const char *WiFlyDevice_string_table[] = {
		// 0-based index, see STI_WIFLY_DEVICE_ list above.
		s_WIFLYDEVICE_JOIN, s_WIFLYDEVICE_ASSOCIATED, s_WIFLYDEVICE_ATTN,
		s_WIFLYDEVICE_VER, s_WIFLYDEVICE_GET_MAC, s_WIFLYDEVICE_GET_IP,
		s_WIFLYDEVICE_GET_GW, s_WIFLYDEVICE_GET_NM, s_WIFLYDEVICE_LEAVE,
		s_WIFLYDEVICE_SET_SSID,
		// 10 follows
		s_WIFLYDEVICE_SET_PASSPHRASE, s_WIFLYDEVICE_NETWORK_SCAN,
		s_WIFLYDEVICE_AOK, s_WIFLYDEVICE_SET_UART_BAUD, s_WIFLYDEVICE_DEAUTH,
		s_WIFLYDEVICE_SET_NTP, s_WIFLYDEVICE_SET_NTP_ENABLE,
		s_WIFLYDEVICE_SET_DEVICEID, s_WIFLYDEVICE_IP_DETAILS,
		s_WIFLYDEVICE_LEAVE_CMD_MODE,
		// 20 follows
		s_WIFLYDEVICE_GET_DNS_DETAILS, s_WIFLYDEVICE_GET_TIME,
		s_WIFLYDEVICE_SET_DHCP, s_WIFLYDEVICE_SET_IP, s_WIFLYDEVICE_SET_NETMASK,
		s_WIFLYDEVICE_SET_GATEWAY, s_WIFLYDEVICE_SET_DNS,
		s_WIFLYDEVICE_ERR_REBOOOT, s_WIFLYDEVICE_ERR_START_FAIL,
		s_WIFLYDEVICE_SET_UART_MODE,
		// 30 follows
		s_WIFLYDEVICE_GET_WLAN, s_WIFLYDEVICE_GET_RSSI,
		s_WIFLYDEVICE_GET_BATTERY, s_WIFLYDEVICE_LIBRARY_VERSION,
		s_WIFLYDEVICE_SET_CHANNEL, s_WIFLYDEVICE_SET_WIFI_AUTH,
		s_WIFLYDEVICE_SET_WIFI_JOIN, s_WIFLYDEVICE_GET_STATUS,
		s_WIFLYDEVICE_GET_MAC_ADDR, s_WIFLYDEVICE_RETURN,
		// 40 follows
		s_WIFLYDEVICE_GET_IP_IND, s_WIFLYDEVICE_GET_NM_IND,
		s_WIFLYDEVICE_GET_GW_IND, s_WIFLYDEVICE_GET_DNS_IND,
		s_WIFLYDEVICE_GET_WLAN_SSID_IND, s_WIFLYDEVICE_GET_RSSI_IND,
		s_WIFLYDEVICE_GET_BATTERY_IND, s_WIFLYDEVICE_GET_WLAN_DEV_IND,
		s_WIFLYDEVICE_GET_TIME_IND, s_WIFLYDEVICE_GET_STATUS_IND,
		// 50 follows
		s_WIFLYDEVICE_GET_IP_UP_IND, s_WIFLYDEVICE_OPEN, s_WIFLYDEVICE_REBOOT,
		s_WIFLYDEVICE_CLOSE, s_WIFLYDEVICE_SET_LOCAL_PORT,
		s_WIFLYDEVICE_SET_REMOTE_PORT, s_WIFLYDEVICE_SET_PROTOCOL,
		s_WIFLYDEVICE_SAVE };

WiFiDevice::WiFiDevice() {

}

void WiFiDevice::setUart(Stream* newUart) {
	uart = newUart;
}

void WiFiDevice::sendCommand(char* buf) {

}

void WiFiDevice::enderCommandMode() {

}
