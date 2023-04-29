# network_info_windows

A package to get Windows Network Adapters Info

This package is related to windows [GetAdaptersAddresses](https://learn.microsoft.com/en-us/windows/win32/api/iphlpapi/nf-iphlpapi-getadaptersaddresses) function (iphlpapi.h)

## supported: 
  * Adapters: 
    * An Ethernet network interface or USB Tethering
    * An IEEE 802.11 wireless network interface. (Wifi)
    * A software loopback network interface. 
* unicast address

example:

```dart
import 'package:network_info_windows/network_info_windows.dart';

NetworkInfoWindows().GetAdaptersInfo();

```
``` json
// check about key and value:
// https://learn.microsoft.com/en-us/windows/win32/api/iptypes/ns-iptypes-ip_adapter_addresses_lh
{
  "{2C2B8B8C-2704-4100-B662-BBB35AF94581}": {
    "ConnectionType": 1,
    "Description": "Realtek RTL8188EU Wireless LAN 802.11n USB 2.0 Network Adapter",
    "Dhcpv4Server": "192.168.0.1",
    "FriendlyName": "WiFi",
    "GatewayAddress": {
      "AF_INET": [],
      "AF_INET6": []
    },
    "IfType": 71,
    "OperStatus": 2,
    "PhysicalAddress": "D0:37:45:F4:66:F5",
    "ReceiveLinkSpeed": 18446744073709552000.0,
    "TransmitLinkSpeed": 18446744073709552000.0,
    "UnicastAddress": {
      "AF_INET": [
        "169.254.41.153"
      ],
      "AF_INET6": [
        "fe80::58b3:b975:b375:a3c0"
      ]
    }
  },
  "{676278AE-59B2-4CFB-A9F4-A5235FB50479}": {
    "ConnectionType": 1,
    "Description": "Microsoft Wi-Fi Direct Virtual Adapter",
    "Dhcpv4Server": "192.168.0.1",
    "FriendlyName": "Local Area Connection* 1",
    "GatewayAddress": {
      "AF_INET": [],
      "AF_INET6": []
    },
    "IfType": 71,
    "OperStatus": 2,
    "PhysicalAddress": "D2:37:45:F4:66:F5",
    "ReceiveLinkSpeed": 18446744073709552000.0,
    "TransmitLinkSpeed": 18446744073709552000.0,
    "UnicastAddress": {
      "AF_INET": [
        "169.254.6.37"
      ],
      "AF_INET6": [
        "fe80::4201:4e4f:c872:5584"
      ]
    }
  },
  "{87617B20-22F5-44F0-A965-C33215F99B4B}": {
    "ConnectionType": 1,
    "Description": "Microsoft Wi-Fi Direct Virtual Adapter #2",
    "Dhcpv4Server": "192.168.0.1",
    "FriendlyName": "Local Area Connection* 2",
    "GatewayAddress": {
      "AF_INET": [],
      "AF_INET6": []
    },
    "IfType": 71,
    "OperStatus": 2,
    "PhysicalAddress": "D0:37:45:F4:66:F5",
    "ReceiveLinkSpeed": 18446744073709552000.0,
    "TransmitLinkSpeed": 18446744073709552000.0,
    "UnicastAddress": {
      "AF_INET": [
        "169.254.80.213"
      ],
      "AF_INET6": [
        "fe80::419e:a5c5:6ede:ed2b"
      ]
    }
  },
  "{D7A513C2-DEE1-11ED-A118-806E6F6E6963}": {
    "ConnectionType": 1,
    "Description": "Software Loopback Interface 1",
    "Dhcpv4Server": "192.168.0.1",
    "FriendlyName": "Loopback Pseudo-Interface 1",
    "GatewayAddress": {
      "AF_INET": [],
      "AF_INET6": []
    },
    "IfType": 24,
    "OperStatus": 1,
    "PhysicalAddress": "D0:37:45:F4:66:F5",
    "ReceiveLinkSpeed": 1073741824,
    "TransmitLinkSpeed": 1073741824,
    "UnicastAddress": {
      "AF_INET": [
        "127.0.0.1"
      ],
      "AF_INET6": [
        "::1"
      ]
    }
  },
  "{F9B858CE-DF36-4640-9709-102C3E198270}": {
    "ConnectionType": 1,
    "Description": "Realtek PCIe GbE Family Controller",
    "Dhcpv4Server": "192.168.0.1",
    "FriendlyName": "Ethernet",
    "GatewayAddress": {
      "AF_INET": [
        "192.168.0.1"
      ],
      "AF_INET6": []
    },
    "IfType": 6,
    "OperStatus": 1,
    "PhysicalAddress": "00:D8:61:A9:35:20",
    "ReceiveLinkSpeed": 1000000000,
    "TransmitLinkSpeed": 1000000000,
    "UnicastAddress": {
      "AF_INET": [
        "192.168.0.154"
      ],
      "AF_INET6": [
        "fe80::c3fa:3b37:b788:91f4"
      ]
    }
  }
}



```
