/*
    * mcal_timer_0.h
    *
    *  Created on: Sep 1, 2019
*/

/* INCLUDS */

#include "../GPIO/mcal_gpio.h"
#include "pic18f4620.h"
#include "../INTERRUPT/mcal_internal_interrupt.h"
#include "../../MCAL/mcal_std_types.h"

/* MACRO DECLARATIONS */

#define TIMER_0_PRESCALER_ENABLE_CFG  1
#define TIMER_0_PRESCALER_DISABLE_CFG 0

#define TIMER_0_RISING_EDGE_SFG       1   
#define TIMER_0_FALLING_EDGE_SFG      0

#define TIMER0_TIMER_MODE             1
#define TIMER0_COUNTER_MODE           0

#define TIMER0_8BIT_REGISTER_MODE     1
#define TIMER0_16BIT_REGISTER_MODE    0

/* MACRO FUNTIONS DECLARATIONS */

#define TIMER_0_ENABLE()                    (T0CONbits.TMR0ON = 1)  // Timer0 is enabled.
#define TIMER_0_DISABLE()                   (T0CONbits.TMR0ON = 0)  // Timer0 is disabled.

#define TIMER_0_8_BIT_MODE()                (T0CONbits.T08BIT = 1)  // Timer0 is configured as an 8-bit timer/counter.
#define TIMER_0_16_BIT_MODE()               (T0CONbits.T08BIT = 0)  // Timer0 is configured as a 16-bit timer/counter.

#define TIMER_0_EXTERNAL_CLOCK_COUNTER()    (T0CONbits.T0CS = 1)    // external clock source from T0CKI pin.
#define TIMER_0_INTERNAL_CLOCK_TIMER()      (T0CONbits.T0CS = 0)    // internal clock source (FOSC/4).

#define TIMER_0_RISING_EDGE()               (T0CONbits.T0SE = 0)    // external clock source from T0CKI pin (on the rising edge).
#define TIMER_0_FALLING_EDGE()              (T0CONbits.T0SE = 1)    // external clock source from T0CKI pin (on the falling edge).

#define TIMER_0_PRESCALER_DISABLE()         (T0CONbits.PSA = 1)     // Prescaler is not assigned to the Timer0 module.
#define TIMER_0_PRESCALER_ENABLE()          (T0CONbits.PSA = 0)     // Prescaler is assigned to the Timer0 module.

/* DATA TYPE DECLARATIONS (ENUMS,UNIONS,STRUCTS) */

typedef enum {
    TIMER_0_PRESCALER_2 = 0,
    TIMER_0_PRESCALER_4,
    TIMER_0_PRESCALER_8,
    TIMER_0_PRESCALER_16,
    TIMER_0_PRESCALER_32,
    TIMER_0_PRESCALER_64,
    TIMER_0_PRESCALER_128,
    TIMER_0_PRESCALER_256
} timer_0_prescaler_section_t;   


typedef struct {
#if ADC_INTURRUPT_FUNCTION_ENABLE == INTERRUPT_ENABLE_FEATURE
    void (*Timer0_InterruptHandler)(void);             /* callback function */
    interrupt_priority_cfg priority;                   /* @ref interrupt_priority_cfg */
#endif
    timer_0_prescaler_section_t prescaler_value;
    uint16 preloaded_value;
    uint8 prescaler_enable     : 1;
    uint8 timer0_counter_edge  : 1;
    uint8 timer0_mode          : 1;
    uint8 timer0_register_size : 1;
    uint8 timer0_reserved      : 4;
} timer_0_config_t;

/* FUNTIONS DECLARATIONS */

Std_ReturnType Timer_0_Init  (const timer_0_config_t *timer_0);  // Initialize Timer0 module.
Std_ReturnType Timer_0_DeInit(const timer_0_config_t *timer_0);  // Deinitialize Timer0 module.
Std_ReturnType Timer_0_Write (const timer_0_config_t *timer_0 , uint16 timer0_value);  // Write a value to Timer0 register.
Std_ReturnType Timer_0_Read  (const timer_0_config_t *timer_0 , uint16 *timer0_value);  // Read a value from Timer0 register.