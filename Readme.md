# ESP32 with FreeRTOS using ESP-IDF

**ESP-IDF** (**Esp**ressif - **I**oT **D**evelopment **F**ramework) the official Espressif toolset for building professional, production-ready firmware for the ESP32.

This repository exists so that I can play around with both Esp-IDF and FreeRTOS.

## Setting up ESP-IDF

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

Then export the environment variables and other required settings

``` bash
. ./export.sh
```

---
