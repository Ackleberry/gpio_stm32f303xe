/**
 * @file gpio.h
 * @author Brooks Anderson
 * @date 
 * @brief 
 */

#ifndef _GPIO_H
#define _GPIO_H

#include <stdint.h>

#include "stm32f303xe.h"

typedef struct {
   uint8_t port;
   uint8_t pin;
} Gpio_Pin_t;

#define GPIO_PIN(port,pin) ((Gpio_Pin_t){ (port), (pin) })

/*!< AHB2 peripherals */
GPIO_TypeDef GPIO_BASE[8];
#define GPIO ((GPIO_TypeDef *)GPIO_BASE)
#define GPIO_PORT_A_IDX (0)
#define GPIO_PORT_B_IDX (1)
#define GPIO_PORT_C_IDX (2)
#define GPIO_PORT_D_IDX (3)
#define GPIO_PORT_E_IDX (4)
#define GPIO_PORT_F_IDX (5)
#define GPIO_PORT_G_IDX (6)
#define GPIO_PORT_H_IDX (7)

#define STM32F303_PIN_PA5    GPIO_PIN(GPIO_PORT_A_IDX, 5)

#define GPIO_Set(p) (GPIO[(p).port].ODR |= (1 << (p).pin))
#define GPIO_Clr(p) (GPIO[(p).port].ODR &= ~(1 << (p).pin))

#endif /* _GPIO_H */