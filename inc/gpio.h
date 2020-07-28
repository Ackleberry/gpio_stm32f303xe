/**
 * @file    gpio.h
 * @author  Brooks Anderson
 * @date    07/27/2020
 * @brief   GPIO Port Abstraction Layer
 */

#ifndef _GPIO_H
#define _GPIO_H

#include <stdint.h>

#include "gpio_ll.h"

/**
 * @brief   Sets a pin logic state to HIGH
 * @note    This abstraction layer provides a default implementation of this
 *          macro. Implementing this macro will override the default one.
 * @param[in] pin      pin identifier
 *
 */
#ifdef GPIO_LL_Set
#   define GPIO_Set(pin)     GPIO_LL_Set(GPIO_ll_GetPinPort(pin), GPIO_ll_GetPinField(pin))
#else
#   define GPIO_Set(pin)    ((void)(pin))
#endif


/**
 * @brief   Clears a pin logic state to LOW
 * @note    This abstraction layer provides a default implementation of this
 *          macro. Implementing this macro will override the default one.
 * @param[in] pin      pin identifier
 *
 */
#ifdef GPIO_LL_Clr
#   define GPIO_Clr(pin)     GPIO_LL_Clr(GPIO_ll_GetPinPort(pin), GPIO_ll_GetPinField(pin))
#else
#   define GPIO_Clr(pin)    ((void)(pin))
#endif

#endif /* _GPIO_H */