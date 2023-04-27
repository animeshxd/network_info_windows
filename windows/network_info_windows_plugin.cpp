#include "network_info.hpp"

#include "network_info_windows_plugin.h"

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>
#include <flutter/standard_method_codec.h>

#include <memory>
#include <sstream>

namespace network_info_windows
{

  // static
  void NetworkInfoWindowsPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarWindows *registrar)
  {
    auto channel =
        std::make_unique<flutter::MethodChannel<flutter::EncodableValue>>(
            registrar->messenger(), "network_info_windows",
            &flutter::StandardMethodCodec::GetInstance());

    auto plugin = std::make_unique<NetworkInfoWindowsPlugin>();

    channel->SetMethodCallHandler(
        [plugin_pointer = plugin.get()](const auto &call, auto result)
        {
          plugin_pointer->HandleMethodCall(call, std::move(result));
        });

    registrar->AddPlugin(std::move(plugin));
  }

  NetworkInfoWindowsPlugin::NetworkInfoWindowsPlugin() {}

  NetworkInfoWindowsPlugin::~NetworkInfoWindowsPlugin() {}

  void NetworkInfoWindowsPlugin::HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue> &method_call,
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result)
  {
    if (method_call.method_name().compare("GetAdaptersInfo") == 0)
    {
      try
      {
        result->Success(flutter::EncodableValue(GetAdaptersInfo().dump()));
      }
      catch (GetAdaptersAddressesFailed &e)
      {
        std::ostringstream str1;
        str1 << e.code;
        result->Error(str1.str());
      }
      catch (const std::exception &e)
      {
        result->Error(e.what());
      }
    }
    else
    {
      result->NotImplemented();
    }
  }

} // namespace network_info_windows
