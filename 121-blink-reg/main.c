#include "hardware/regs/addressmap.h"
#include "hardware/regs/sio.h"
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const uint LED_PIN = 25;

volatile uint32_t *gpio_out_set = (uint32_t *)(SIO_BASE + SIO_GPIO_OUT_SET_OFFSET);
volatile uint32_t *gpio_out_clr = (uint32_t *)(SIO_BASE + SIO_GPIO_OUT_CLR_OFFSET);
const uint32_t led_mask = 1u << LED_PIN;

int main() {
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    
    while (1){
        gpio_put(LED_PIN, 1);
        sleep_ms(250);
        gpio_put(LED_PIN, 0);
        sleep_ms(1000);
    }
}