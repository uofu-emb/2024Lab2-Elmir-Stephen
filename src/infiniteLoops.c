void mainTaskWhileLoop(char c) {
    while(true) {
        c = getchar();
        if (c <= 'z' && c >= 'a') putchar(c - 32);
        else if (c >= 'A' && c <= 'Z') putchar(c + 32);
        else putchar(c);
    }
}

void  blinkTaskWhileLoop(int count, bool on) {
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, on);
        if (count++ % 11) on = !on;
        vTaskDelay(500);

}