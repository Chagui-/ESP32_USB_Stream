/*
 * Compatibility shim for Arduino builds.
 *
 * ESP-IDF components normally generate a top-level `sdkconfig.h`.
 * Arduino-ESP32 does not provide it in the library compilation context,
 * but this USB stream code expects it. We map the required CONFIG_* macros
 * to the library's `include/arduino_config.h`.
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

// Provide ESP_IDF_VERSION / ESP_IDF_VERSION_VAL when available
#if __has_include("esp_idf_version.h")
#include "esp_idf_version.h"
#endif

// Pull in the library's configuration defaults
#include "include/arduino_config.h"

#ifdef __cplusplus
} // extern "C"
#endif

