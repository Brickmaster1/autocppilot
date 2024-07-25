#include <iostream>
#include "pico/stdlib.h"

int main() {
    stdio_init_all();
    while (true) {
        std::cout << "Hello, world!" << std::endl;
        sleep_ms(1000);
    }
}