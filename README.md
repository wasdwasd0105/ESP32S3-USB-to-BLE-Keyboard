# USB Keyboard to Bluetooth LE converter for ESP32-S3

This project can convert USB only Keyboard to a Bluetooth LE keyboard. It needs ESP32-S3 (not S2) becacuse this SOC supports both BLE and USB host function.

This project is based on https://github.com/touchgadget/esp32-usb-host-demos for USB host and https://github.com/T-vK/ESP32-BLE-Keyboard for BLE keyboard.

## Installation
- (Make sure you can use the ESP32 with the Arduino IDE. [Instructions can be found here.](https://github.com/espressif/arduino-esp32#installation-instructions))
- [Download the latest release of this library from the release page.](https://github.com/wasdwasd0105/ESP32S3-USB-to-BLE-Keyboard/releases)
- In the Arduino IDE go to "Sketch" -> "Include Library" -> "Add .ZIP Library..." and select the file you just downloaded.
- You can now go to "File" -> "Examples" -> "ESP32 BLE Keyboard" and select any of the examples to get started.
- Add elapsedMillis and NimBLE-Arduino library

## Use
- Compile the USBKeyboardToBLE.ino and flash
- Connect the Keyboard to the USB host port on ESP32-S3
- Connect Bluetooth and use

## Todo
 - [ ] Test keyboard
 - [ ] Support muitple BLE Host
 - [ ] Read Numlock/Capslock/Scrolllock state
 - [ ] Sleep if unused