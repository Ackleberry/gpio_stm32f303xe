/**
 * @file gpio.h
 * @author Brooks Anderson
 * @date 
 * @brief 
 */

#ifndef _GPIO_H
#define _GPIO_H

#include <stdint.h>

#include "gpio_stm32f303.h"

#define HW_LINK(func, x)  GPIO_STM32F303_##func(x)

#define GPIO_Set(x)     HW_LINK(Set, x)
#define GPIO_Clr(x)     HW_LINK(Clr, x)

#endif /* _GPIO_H */