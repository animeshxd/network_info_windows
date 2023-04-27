import 'package:flutter_test/flutter_test.dart';
import 'package:network_info_windows/network_info_windows.dart';
import 'package:network_info_windows/network_info_windows_platform_interface.dart';
import 'package:network_info_windows/network_info_windows_method_channel.dart';
import 'package:plugin_platform_interface/plugin_platform_interface.dart';

class MockNetworkInfoWindowsPlatform
    with MockPlatformInterfaceMixin
    implements NetworkInfoWindowsPlatform {

  @override
  Future<String?> getPlatformVersion() => Future.value('42');
}

void main() {
  final NetworkInfoWindowsPlatform initialPlatform = NetworkInfoWindowsPlatform.instance;

  test('$MethodChannelNetworkInfoWindows is the default instance', () {
    expect(initialPlatform, isInstanceOf<MethodChannelNetworkInfoWindows>());
  });

  test('getPlatformVersion', () async {
    NetworkInfoWindows networkInfoWindowsPlugin = NetworkInfoWindows();
    MockNetworkInfoWindowsPlatform fakePlatform = MockNetworkInfoWindowsPlatform();
    NetworkInfoWindowsPlatform.instance = fakePlatform;

    expect(await networkInfoWindowsPlugin.getPlatformVersion(), '42');
  });
}
