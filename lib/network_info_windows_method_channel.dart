import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';

import 'network_info_windows_platform_interface.dart';

/// An implementation of [NetworkInfoWindowsPlatform] that uses method channels.
class MethodChannelNetworkInfoWindows extends NetworkInfoWindowsPlatform {
  /// The method channel used to interact with the native platform.
  @visibleForTesting
  final methodChannel = const MethodChannel('network_info_windows');

  @override
  Future<String?> getPlatformVersion() async {
    final version = await methodChannel.invokeMethod<String>('getPlatformVersion');
    return version;
  }
}
