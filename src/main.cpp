#include <cstdio>
#include "pico/stdlib.h"
#include "pico/status_led.h"

int main() {
    stdio_init_all();
    status_led_init();

    uint32_t n = 0;
    while (true) {
        status_led_set_state(n & 1);
        printf("tick %lu\n", n++);
        sleep_ms(500);
    }
}