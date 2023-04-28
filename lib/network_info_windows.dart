import 'network_info_windows_platform_interface.dart';

class NetworkInfoWindows {
  // ignore: non_constant_identifier_names
  Future<Map<String, Map<String, dynamic>>> GetAdaptersInfo() {
    return NetworkInfoWindowsPlatform.instance.GetAdaptersInfo();
  }
}
