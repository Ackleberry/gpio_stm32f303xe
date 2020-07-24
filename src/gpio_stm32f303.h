/**
 * @file gpio_stm32f303.h
 * @author Brooks Anderson
 * @date 
 * @brief 
 */

#ifndef _GPIO_STM32F303_H
#define _GPIO_STM32F303_H

#include <stdint.h>

#include "stm32f303xe.h"

#define GPIO_REG_T GPIO_TypeDef
typedef struct _Gpio_Pin_t
{
   GPIO_REG_T *portPtr;
   uint8_t pinNum;
} Gpio_Pin_t;

#define GPIO_MAP(portPtr,pinNum) ((Gpio_Pin_t){ (portPtr), (pinNum) })

#define STM32F303_PIN_PA0        GPIO_MAP(GPIOA, 0)
#define STM32F303_PIN_PA1        GPIO_MAP(GPIOA, 1)
#define STM32F303_PIN_PA2        GPIO_MAP(GPIOA, 2)
#define STM32F303_PIN_PA3        GPIO_MAP(GPIOA, 3)
#define STM32F303_PIN_PA4        GPIO_MAP(GPIOA, 4)
#define STM32F303_PIN_PA5        GPIO_MAP(GPIOA, 5)
#define STM32F303_PIN_PA6        GPIO_MAP(GPIOA, 6)
#define STM32F303_PIN_PA7        GPIO_MAP(GPIOA, 7)
#define STM32F303_PIN_PA8        GPIO_MAP(GPIOA, 8)
#define STM32F303_PIN_PA9        GPIO_MAP(GPIOA, 9)
#define STM32F303_PIN_PA10       GPIO_MAP(GPIOA, 10)
#define STM32F303_PIN_PA11       GPIO_MAP(GPIOA, 11)
#define STM32F303_PIN_PA12       GPIO_MAP(GPIOA, 12)
#define STM32F303_PIN_PA13       GPIO_MAP(GPIOA, 13)
#define STM32F303_PIN_PA14       GPIO_MAP(GPIOA, 14)
#define STM32F303_PIN_PA15       GPIO_MAP(GPIOA, 15)


#define GPIO_STM32F303_Set(x)   ( (x).portPtr->BSRR |= (1 << (x).pinNum) )
#define GPIO_STM32F303_Clr(x)   ( (x).portPtr->BRR &= ~(1 << (x).pinNum) )

#endif /* _GPIO_STM32F303_H */