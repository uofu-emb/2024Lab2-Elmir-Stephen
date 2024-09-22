#include "infiniteLoops.h"
#include <stdio.h>
#include <pico/stdlib.h>
#include <stdint.h>
#include <unity.h>


#include <pico/cyw43_arch.h>

#include "unity_config.h"


void setUp(void) {}

void tearDown(void) {}

void test_mainTaskWhileLoop()
{

    TEST_ASSERT_TRUE_MESSAGE(mainTaskWhileLoop('f') == 'F',"Character conversion failed");
    TEST_ASSERT_TRUE_MESSAGE(mainTaskWhileLoop('F') == 'f',"Character conversion failed");
    TEST_ASSERT_TRUE_MESSAGE(mainTaskWhileLoop('1') == '1',"Character conversion failed");
}

void test_blinkTaskWhileLoop(void)
{

    hard_assert(cyw43_arch_init() == PICO_OK);
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
    bool on = false;
    int x = 50;
    on = blinkTaskWhileLoop(&x, on);
    TEST_ASSERT_TRUE_MESSAGE(x == 51, "count increment failed");
    TEST_ASSERT_TRUE_MESSAGE(on == true, "on/off function failed");
    on = blinkTaskWhileLoop(&x, on);
    TEST_ASSERT_EQUAL(cyw43_arch_gpio_get(CYW43_WL_GPIO_LED_PIN), true);
}

int main (void)
{
    stdio_init_all();
    sleep_ms(5000); // Give time for TTY to attach.
    printf("Start tests\n");
    UNITY_BEGIN();
    RUN_TEST(test_mainTaskWhileLoop);
    RUN_TEST(test_blinkTaskWhileLoop);
    sleep_ms(5000);
    return UNITY_END();
}
