import 'dart:convert';

import 'package:flutter/material.dart';
import 'dart:async';

import 'package:flutter/services.dart';
import 'package:network_info_windows/network_info_windows.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatefulWidget {
  MyApp({super.key});
  final _networkInfo = NetworkInfoWindows();

  @override
  State<MyApp> createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        body: Center(
          child: FutureBuilder<Map<String, dynamic>>(
            future: widget._networkInfo.GetAdaptersInfo(),
            initialData: const {},
            builder: (context, snapshot) {
              return SingleChildScrollView(
                child: Text(
                  const JsonEncoder.withIndent('  ').convert(snapshot.data),
                ),
              );
            },
          ),
        ),
      ),
    );
  }
}
