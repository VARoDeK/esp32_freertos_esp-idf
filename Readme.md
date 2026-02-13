# ESP32 with FreeRTOS using ESP-IDF

**ESP-IDF** (**Esp**ressif - **I**oT **D**evelopment **F**ramework) the official Espressif toolset for building professional, production-ready firmware for the ESP32.

This repository exists so that I can play around with both Esp-IDF and FreeRTOS.

The board I am using (as per the description of DigiKey): ESP32 Huzzah32 802.11 b/g/n (WiFi/WLAN/Wi-Fi 4), Bluetooth® Smart Ready 4.x Dual Mode (BLE) RF (Transceiver) 2.4GHz Evaluation Board

## 1) - Setting up ESP-IDF

Run:

``` bash
git submodule init
git submodule update
```

Now we will install the SDK. This will basically unpack the tools and place them in your home directory.

``` bash
cd esp-idf
./install.sh
```

## 2) - Export the environment

Once the SDK and its supporting files are installed, then export the environment variables and other required settings.

``` bash
. ./export.sh
```

## 3) - Blinky example

The steps for building complex projects might differ, but these steps, used for blinky, give you the basic usage of the SDK.

Let's look at the project situated at `blinky/blink-led_0`. Write the code in `main/blink-led_0.c`

Then set-up the target (I am using `esp32`):

``` bash
idf.py set-target esp32
```

Now build:

``` bash
idf.py build
```

Now Flash:

``` bash
idf.py flash

# You can also define port number. For example on my system the device appeared as /dev/ttyUSB0
#     idf.py --port /dev/ttyUSB0 flash
```

---
