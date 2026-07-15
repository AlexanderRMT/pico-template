#include <stdio.h>
#include "pico/stdlib.h"

int main(void) {
    stdio_init_all();

    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);

    uint32_t n = 0;
    while (true) {
        gpio_xor_mask(1u << PICO_DEFAULT_LED_PIN);
        printf("tick %lu\n", n++);
        sleep_ms(500);
    }
}