#include "infiniteLoops.h"
#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "pico/cyw43_arch.h"

#include "FreeRTOS.h"
#include "task.h"

char mainTaskWhileLoop(char c) {
        if (c <= 'z' && c >= 'a') return (c - 32);
        else if (c >= 'A' && c <= 'Z') return (c + 32);
        else return c;
}

bool blinkTaskWhileLoop(int *count, bool on) {
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, on);
        if (*count % 11) on = !on;
        *count = *count + 1;
        return on;
}