/* 
 * File:   app.c
 * Author: houda
 *
 * Created on February 18, 2024, 3:42 PM
 */

#include "app.h"

void adc_isr_fun(void);

pin_config_p PIN_C0 = {
    .direction = PIC_OUTPUT,
    .logic     = PIC_LOW,
    .pin       = PIN_0,
    .port      = PORTC_P
};

adc_config_t adc_1 ={
    .adc_aquisition_time  = ADC_12_TAD,
    .adc_conversion_clock = ADC_FOSC_16,
    .adc_Channel_select   = ADC_CHANNEL_0,
    .adc_voltage_ref      = ADC_VOLTAGE_REF_DISABLE,
    .adc_result_format    = ADC_RIGHT_JUSTIFIED_RESULT,
    .adc_InterruptHandler = adc_isr_fun
};

uint16 adc_res_0 = 0;
uint8  flag_int  = 0;

//uint16 adc_res_1 = 0;
//uint16 adc_res_2 = 0;

Std_ReturnType ret = E_NOT_OK;

int main() {

    app_intialize();
    
    while(1){
        
        ret = ADC_GetConversion_Interrupt(&adc_1, ADC_CHANNEL_0);
     
    }
    return (EXIT_SUCCESS);
}


void adc_isr_fun(void){
    ret = E_NOT_OK;
    flag_int++;
    ret = ADC_GetResult(&adc_1, &adc_res_0);
}

void app_intialize(void){
    Std_ReturnType ret = E_NOT_OK;
    ret = ADC_Init(&adc_1);
    // ret = gpio_pin_initialization(&PIN_C0);
    ecu_intialize();
}