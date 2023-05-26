/*
 * MIT License
 *
 * Copyright (c) 2021 touchgadgetdev@gmail.com
 * Copyright (c) 2023 wasdwasd0105@gmail.com
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef _USBKEYBOARDHOSTLIB_H
#define _USBKEYBOARDHOSTLIB_H

#include <elapsedMillis.h>
#include <usb/usb_host.h>


const TickType_t HOST_EVENT_TIMEOUT = 1;
const TickType_t CLIENT_EVENT_TIMEOUT = 1;
const size_t USB_HID_DESC_SIZE = 9;


typedef void (*usb_host_enum_cb_t)(const usb_config_desc_t *config_desc);
static usb_host_enum_cb_t _USB_host_enumerate;

typedef union {
    struct {
        uint8_t bLength;                    /**< Size of the descriptor in bytes */
        uint8_t bDescriptorType;            /**< Constant name specifying type of HID descriptor. */
        uint16_t bcdHID;                    /**< USB HID Specification Release Number in Binary-Coded Decimal (i.e., 2.10 is 210H) */
        uint8_t bCountryCode;               /**< Numeric expression identifying country code of the localized hardware. */
        uint8_t bNumDescriptor;             /**< Numeric expression specifying the number of class descriptors. */
        uint8_t bHIDDescriptorType;         /**< Constant name identifying type of class descriptor. See Section 7.1.2: Set_Descriptor Request for a table of class descriptor constants. */
        uint16_t wHIDDescriptorLength;      /**< Numeric expression that is the total size of the Report descriptor. */
        uint8_t bHIDDescriptorTypeOpt;      /**< Optional constant name identifying type of class descriptor. See Section 7.1.2: Set_Descriptor Request for a table of class descriptor constants. */
        uint16_t wHIDDescriptorLengthOpt;   /**< Optional numeric expression that is the total size of the Report descriptor. */
    } USB_DESC_ATTR;
    uint8_t val[USB_HID_DESC_SIZE];
} usb_hid_desc_t;

class USBKeyboardHostLib {
private:
    static bool isKeyboard;
    static uint8_t KeyboardInterval;
    static elapsedMillis KeyboardTimer;

    static const size_t KEYBOARD_IN_BUFFER_SIZE = 8;
    static usb_transfer_t *KeyboardIn;
    static bool isKeyboardPolling;

    static void keyboard_transfer_cb(usb_transfer_t *transfer);
    static void check_interface_desc_boot_keyboard(const void *p);
    static void prepare_endpoint(const void *p);
    static void show_config_desc_full(const usb_config_desc_t *config_desc);

    void usbh_setup(void (*show_config_desc_full)(const usb_config_desc_t *config_desc));
    void usbh_task();

public:
    static uint8_t *usb_data_buffer;
    static bool isKeyboardPollingPub;
    static bool isKeyboardReady;
    void begin();
    void pollingData();
};


#endif // _USBKEYBOARDHOSTLIB_H