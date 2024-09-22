#pragma once
#include "pico/stdlib.h"
#include <stdbool.h>
#include "FreeRTOS.h"
#include "task.h"

char mainTaskWhileLoop(char c);
bool blinkTaskWhileLoop(int *count, bool on);


