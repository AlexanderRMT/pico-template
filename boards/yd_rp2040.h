#ifndef _BOARDS_YD_RP2040_H
#define _BOARDS_YD_RP2040_H

// pico_cmake_set PICO_PLATFORM=rp2040

// --- LEDs ---
#define PICO_DEFAULT_LED_PIN            25
#define PICO_DEFAULT_WS2812_PIN         23   // freed by the LDO swap; NOT DC-DC control

// --- Buttons ---
#define YD_USER_BUTTON_PIN              24   // to GND, no external pull-up

// --- UART ---
#define PICO_DEFAULT_UART               0
#define PICO_DEFAULT_UART_TX_PIN        0
#define PICO_DEFAULT_UART_RX_PIN        1

// --- I2C ---
#define PICO_DEFAULT_I2C                0
#define PICO_DEFAULT_I2C_SDA_PIN        4
#define PICO_DEFAULT_I2C_SCL_PIN        5

// --- SPI ---
#define PICO_DEFAULT_SPI                0
#define PICO_DEFAULT_SPI_SCK_PIN        18
#define PICO_DEFAULT_SPI_TX_PIN         19
#define PICO_DEFAULT_SPI_RX_PIN         16
#define PICO_DEFAULT_SPI_CSN_PIN        17

// --- Flash ---
// Confirmed by OpenOCD SFDP: "size = 16384 KiB in 4096 sectors"
#define PICO_FLASH_SIZE_BYTES           (16 * 1024 * 1024)
#define PICO_BOOT_STAGE2_CHOOSE_W25Q080 1
#define PICO_FLASH_SPI_CLKDIV           2

// Uncomment if it hangs before main(). Clone crystals stabilise slower.
// #define PICO_XOSC_STARTUP_DELAY_MULTIPLIER 64

#endif