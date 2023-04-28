#include <winsock2.h>
#include <iphlpapi.h>
#include <ws2tcpip.h>
#include "json.hpp"
#include <comdef.h>

#define WORKING_BUFFER_SIZE 15000
#define MAX_TRIES 3

#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))

/* Note: could also use malloc() and free() */

std::string AddressToString(SOCKET_ADDRESS Address);

class GetAdaptersAddressesFailed : public std::exception
{
public:
    GetAdaptersAddressesFailed(DWORD code) : code(code){};
    DWORD code;
};

nlohmann::json GetAdaptersInfo()
{
    nlohmann::json json;
    nlohmann::json data;

    /* Declare and initialize variables */
    DWORD dwRetVal = 0;


    // Set the flags to pass to GetAdaptersAddresses
    ULONG flags = GAA_FLAG_INCLUDE_PREFIX | GAA_FLAG_SKIP_ANYCAST | GAA_FLAG_SKIP_MULTICAST | GAA_FLAG_SKIP_DNS_SERVER | GAA_FLAG_INCLUDE_GATEWAYS;

    // default to unspecified address family (both)
    ULONG family = AF_INET;


    PIP_ADAPTER_ADDRESSES pAddresses = NULL;
    ULONG outBufLen = 0;
    ULONG Iterations = 0;

    PIP_ADAPTER_ADDRESSES pCurrAddresses = NULL;
    PIP_ADAPTER_UNICAST_ADDRESS pUnicast = NULL;

    // Allocate a 15 KB buffer to start with.
    outBufLen = WORKING_BUFFER_SIZE;

    do
    {

        pAddresses = (IP_ADAPTER_ADDRESSES *)MALLOC(outBufLen);
        if (pAddresses == NULL)
        {
            throw std::exception("Memory allocation failed for IP_ADAPTER_ADDRESSES struct");
        }

        dwRetVal = GetAdaptersAddresses(family, flags, NULL, pAddresses, &outBufLen);

        if (dwRetVal == ERROR_BUFFER_OVERFLOW)
        {
            FREE(pAddresses);
            pAddresses = NULL;
        }
        else
        {
            break;
        }

        Iterations++;

    } while ((dwRetVal == ERROR_BUFFER_OVERFLOW) && (Iterations < MAX_TRIES));

    if (dwRetVal == NO_ERROR)
    {
        // If successful, output some information from the data we received
        pCurrAddresses = pAddresses;
        while (pCurrAddresses)
        {
            if (pCurrAddresses->IfType == MIB_IF_TYPE_ETHERNET || pCurrAddresses->IfType == IF_TYPE_IEEE80211)
            {

                data["OperStatus"] = pCurrAddresses->OperStatus;

                pUnicast = pCurrAddresses->FirstUnicastAddress;

                std::vector<std::string> ipv4s;
                std::vector<std::string> ipv6s;

                while (pUnicast != NULL)
                {
                    if (pUnicast->Address.lpSockaddr->sa_family == AF_INET)
                    {
                        ipv4s.push_back(AddressToString(pUnicast->Address));
                    }
                    else if (pUnicast->Address.lpSockaddr->sa_family == AF_INET6)
                    {
                        ipv6s.push_back(AddressToString(pUnicast->Address));
                    }
                    pUnicast = pUnicast->Next;
                }
                data["UnicastAddress"] = {
                    {"AF_INET", ipv4s},
                    {"AF_INET6", ipv6s}
                };
                data["Description"] = _bstr_t(pCurrAddresses->Description);
                data["FriendlyName"] = _bstr_t(pCurrAddresses->FriendlyName);

                if (pCurrAddresses->PhysicalAddressLength != 0)
                {
                    auto &PhysicalAddress = pCurrAddresses->PhysicalAddress;

                    char mac[18];
                    sprintf_s(mac, "%.2X:%.2X:%.2X:%.2X:%.2X:%.2X",
                              PhysicalAddress[0], PhysicalAddress[1], PhysicalAddress[2],
                              PhysicalAddress[3], PhysicalAddress[4], PhysicalAddress[5]);

                    data["PhysicalAddress"] = mac;
                }

                data["IfType"] = pCurrAddresses->IfType;
                data["OperStatus"] = pCurrAddresses->OperStatus;
                /* printf("\tIpv6IfIndex (IPv6 interface): %u\n",
                     pCurrAddresses->Ipv6IfIndex);
                 printf("\tZoneIndices (hex): ");
                 for (i = 0; i < 16; i++)
                     printf("%lx ", pCurrAddresses->ZoneIndices[i]);
                 printf("\n");*/

                data["TransmitLinkSpeed"] = pCurrAddresses->TransmitLinkSpeed;
                data["ReceiveLinkSpeed"] = pCurrAddresses->ReceiveLinkSpeed;
                json[pCurrAddresses->AdapterName] = data;
            }
            pCurrAddresses = pCurrAddresses->Next;
        }
    }
    else
    {
        if (dwRetVal == ERROR_NO_DATA)
        {
            if (pAddresses)
                FREE(pAddresses);
            throw std::exception("No addresses were found for the requested parameters");
        }
        else
        {
            if (pAddresses)
                FREE(pAddresses);
            throw GetAdaptersAddressesFailed(dwRetVal);
        }
    }

    if (pAddresses)
        FREE(pAddresses);
    return json;
}

std::string AddressToString(SOCKET_ADDRESS Address)
{
    if (Address.lpSockaddr->sa_family == AF_INET)
    {
        char szIpAddr[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &((struct sockaddr_in *)Address.lpSockaddr)->sin_addr, szIpAddr, sizeof(szIpAddr));
        return std::string(szIpAddr);
    }
    else if (Address.lpSockaddr->sa_family == AF_INET6)
    {
        char szIpAddr[INET6_ADDRSTRLEN];
        inet_ntop(AF_INET6, &((struct sockaddr_in6 *)Address.lpSockaddr)->sin6_addr, szIpAddr, sizeof(szIpAddr));
        return std::string(szIpAddr);
    }
    return std::string();
}