
import 'network_info_windows_platform_interface.dart';

class NetworkInfoWindows {
  Future<String?> getPlatformVersion() {
    return NetworkInfoWindowsPlatform.instance.getPlatformVersion();
  }
}
