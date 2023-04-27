import 'package:plugin_platform_interface/plugin_platform_interface.dart';

import 'network_info_windows_method_channel.dart';

abstract class NetworkInfoWindowsPlatform extends PlatformInterface {
  /// Constructs a NetworkInfoWindowsPlatform.
  NetworkInfoWindowsPlatform() : super(token: _token);

  static final Object _token = Object();

  static NetworkInfoWindowsPlatform _instance = MethodChannelNetworkInfoWindows();

  /// The default instance of [NetworkInfoWindowsPlatform] to use.
  ///
  /// Defaults to [MethodChannelNetworkInfoWindows].
  static NetworkInfoWindowsPlatform get instance => _instance;

  /// Platform-specific implementations should set this with their own
  /// platform-specific class that extends [NetworkInfoWindowsPlatform] when
  /// they register themselves.
  static set instance(NetworkInfoWindowsPlatform instance) {
    PlatformInterface.verifyToken(instance, _token);
    _instance = instance;
  }

  Future<String?> getPlatformVersion() {
    throw UnimplementedError('platformVersion() has not been implemented.');
  }
}
