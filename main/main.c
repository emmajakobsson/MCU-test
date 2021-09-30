#include <stdio.h>
#include "driver/gpio.h"
#include "driver/ledc.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include <driver/adc.h>

#define LED_GREEN 32
#define LED_YELLOW 25
#define LED_RED 27
#define SENSOR 33

/*
static void configure_led(void)
{
    int LED[3] = {LED_GREEN, LED_RED, LED_YELLOW};

    for(int i = 0; i < 3; i++){
        //reset pins
        gpio_reset_pin(LED[i]);*/
        /* Set the GPIO as a push/pull output */
//        gpio_set_direction(LED[i], GPIO_MODE_OUTPUT);
 //   }
//}

static void configure_sensor(void)
{
    //reset pins
    gpio_reset_pin(ADC1_CHANNEL_5);
    /* Set the GPIO as a push/pull output */
    //gpio_set_direction(33, GPIO_MODE_INPUT);
    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(ADC1_CHANNEL_5,ADC_ATTEN_6db);
}

void app_main(void)
{
    /*int pin_state = 1;
    int LED[3] = {LED_RED, LED_YELLOW, LED_GREEN};
    int k = 0;*/
    int data = -2;

    //cinfigure pins for the leds
    //configure_led();
    configure_sensor();

    while(1){
        /*//turn led on
        gpio_set_level(LED[k%3], pin_state);
        //change led state
        pin_state = !pin_state;
        //delay
        vTaskDelay(10);
        k++;*/

        data = adc1_get_raw(ADC1_CHANNEL_5);
        printf("Sensor reading: %d\n",data);
        vTaskDelay(100);
    }
}
