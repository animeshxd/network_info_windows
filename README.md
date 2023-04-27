# network_info_windows

A package to get Windows Network Adapters Info

This package is related to windows [GetAdaptersAddresses](https://learn.microsoft.com/en-us/windows/win32/api/iphlpapi/nf-iphlpapi-getadaptersaddresses) function (iphlpapi.h)

* Only supported Ethernet and Wifi 
* Only unicast address supported

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
    "Description": "Realtek RTL8188EU Wireless LAN 802.11n USB 2.0 Network Adapter",
    "FriendlyName": "WiFi",
    "IPv4 Address": [
      "169.254.41.153"
    ],
    "IPv6 Address": [],
    "IfType": 71,
    "OperStatus": 2,
    "PhysicalAddress": "D0:37:45:F4:66:F5",
    "ReceiveLinkSpeed": 18446744073709552000.0,
    "TransmitLinkSpeed": 18446744073709552000.0
  },
  "{676278AE-59B2-4CFB-A9F4-A5235FB50479}": {
    "Description": "Microsoft Wi-Fi Direct Virtual Adapter",
    "FriendlyName": "Local Area Connection* 1",
    "IPv4 Address": [
      "169.254.6.37"
    ],
    "IPv6 Address": [],
    "IfType": 71,
    "OperStatus": 2,
    "PhysicalAddress": "D2:37:45:F4:66:F5",
    "ReceiveLinkSpeed": 18446744073709552000.0,
    "TransmitLinkSpeed": 18446744073709552000.0
  },
  "{87617B20-22F5-44F0-A965-C33215F99B4B}": {
    "Description": "Microsoft Wi-Fi Direct Virtual Adapter #2",
    "FriendlyName": "Local Area Connection* 2",
    "IPv4 Address": [
      "169.254.80.213"
    ],
    "IPv6 Address": [],
    "IfType": 71,
    "OperStatus": 2,
    "PhysicalAddress": "D0:37:45:F4:66:F5",
    "ReceiveLinkSpeed": 18446744073709552000.0,
    "TransmitLinkSpeed": 18446744073709552000.0
  },
  "{F9B858CE-DF36-4640-9709-102C3E198270}": {
    "Description": "Realtek PCIe GbE Family Controller",
    "FriendlyName": "Ethernet",
    "IPv4 Address": [
      "192.168.0.154"
    ],
    "IPv6 Address": [],
    "IfType": 6,
    "OperStatus": 1,
    "PhysicalAddress": "00:D8:61:A9:35:20",
    "ReceiveLinkSpeed": 1000000000,
    "TransmitLinkSpeed": 1000000000
  }
}


```
