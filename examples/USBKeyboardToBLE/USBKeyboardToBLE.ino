#include <BleKeyboard.h>
#include <USBKeyboardHostLib.h>

USBKeyboardHostLib usbKeyboardHostLib;
BleKeyboard bleKeyboard;

void setup() {

  Serial.begin(115200);
  Serial.println();

  Serial.println("Starting usb host!");
  usbKeyboardHostLib.begin();
  
  Serial.println("Starting BLE service!");
  bleKeyboard.begin();

}

void loop() {
  
  //Get USB data
  usbKeyboardHostLib.pollingData();
  
  if (usbKeyboardHostLib.usb_data_buffer != NULL && usbKeyboardHostLib.isKeyboardPollingPub){

    // Clear the polling flag
    usbKeyboardHostLib.isKeyboardPollingPub = 0;

    ESP_LOGI("", "HID report: %02x %02x %02x %02x %02x %02x %02x %02x",
                        usbKeyboardHostLib.usb_data_buffer[0], usbKeyboardHostLib.usb_data_buffer[1], usbKeyboardHostLib.usb_data_buffer[2], usbKeyboardHostLib.usb_data_buffer[3], usbKeyboardHostLib.usb_data_buffer[4],
                        usbKeyboardHostLib.usb_data_buffer[5], usbKeyboardHostLib.usb_data_buffer[6], usbKeyboardHostLib.usb_data_buffer[7]);

    // Send USB Keyboard to BLE
    bleKeyboard.sendUSBReport(usbKeyboardHostLib.usb_data_buffer);

  }

}