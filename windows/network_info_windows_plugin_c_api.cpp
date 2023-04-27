#include "include/network_info_windows/network_info_windows_plugin_c_api.h"

#include <flutter/plugin_registrar_windows.h>

#include "network_info_windows_plugin.h"

void NetworkInfoWindowsPluginCApiRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  network_info_windows::NetworkInfoWindowsPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}
