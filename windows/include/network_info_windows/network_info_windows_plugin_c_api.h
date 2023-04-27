#ifndef FLUTTER_PLUGIN_NETWORK_INFO_WINDOWS_PLUGIN_C_API_H_
#define FLUTTER_PLUGIN_NETWORK_INFO_WINDOWS_PLUGIN_C_API_H_

#include <WinSock2.h> // fix includes

#include <flutter_plugin_registrar.h>

#ifdef FLUTTER_PLUGIN_IMPL
#define FLUTTER_PLUGIN_EXPORT __declspec(dllexport)
#else
#define FLUTTER_PLUGIN_EXPORT __declspec(dllimport)
#endif

#if defined(__cplusplus)
extern "C" {
#endif

FLUTTER_PLUGIN_EXPORT void NetworkInfoWindowsPluginCApiRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar);

#if defined(__cplusplus)
}  // extern "C"
#endif

#endif  // FLUTTER_PLUGIN_NETWORK_INFO_WINDOWS_PLUGIN_C_API_H_
