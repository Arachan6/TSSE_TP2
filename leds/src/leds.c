#include "leds.h"

#define ALL_LEDS_OFF        0x0000
#define LEDS_TO_BIT_OFFSET  1
#define FIRST_BIT           1

static uint16_t * port_address;

static uint16_t LedToMask(uint8_t led){
    return (FIRST_BIT << (led - LEDS_TO_BIT_OFFSET));
}

void LedsInit(uint16_t* direccion){
    port_address = direccion;
    *port_address = ALL_LEDS_OFF;

}

void LedsTurnOnSingle(uint8_t led){
    *port_address |= LedToMask(led);
}

void LedsTurnOffSingle(uint8_t led){
    *port_address &= ~LedToMask(led);
}

