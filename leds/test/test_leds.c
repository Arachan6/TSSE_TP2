#include "unity.h"
#include "leds.h"

static uint16_t leds_virtuales = 0xFFFF;

void setUp(void){
    LedsInit(&leds_virtuales); 
}


void test_todos_los_leds_inician_apagados(void){
    uint16_t leds_virtuales = 0xFFFF;
    LedsInit(&leds_virtuales); 
    TEST_ASSERT_EQUAL_HEX16(0x0000, leds_virtuales);
}

void test_prender_led_individual(void){
    LedsTurnOnSingle(4);
    TEST_ASSERT_EQUAL_HEX16(0x0008, leds_virtuales);
}

void test_apagar_led_individual(void){
    LedsTurnOnSingle(4);
    LedsTurnOffSingle(4);
    TEST_ASSERT_EQUAL_HEX16(0x0000, leds_virtuales);
}

void test_prender_y_apagar_algunos_leds(void){
    LedsTurnOnSingle(4);
    LedsTurnOnSingle(6);
    LedsTurnOffSingle(4);
    LedsTurnOffSingle(8);
    TEST_ASSERT_EQUAL_HEX16(0x0020, leds_virtuales);
}










