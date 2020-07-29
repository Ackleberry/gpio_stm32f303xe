/**
 * @file    gpio_ll.h
 * @author  Brooks Anderson
 * @date    07/27/2020
 * @brief   Low-level General Purpose Input Output header for STM32F303xE
 * @details This implementation specific headerfile should never be directly
 *          called in application code to ensure portability.
 */

#ifndef _GPIO_ll
#define _GPIO_ll

#include <stdint.h>

#include "stm32f303xe.h"

/**
 * @brief   Pin Port Identifier Type.
 * @details This type can be a scalar or some kind of pointer. Its use is
 *          implementation specific. This type is often defined from a
 *          pre-existing vendor specific type.
 */
typedef GPIO_TypeDef* Gpio_ll_Port_t;

/**
 * @brief   Pin Field Identifier Type.
 */
typedef uint8_t Gpio_ll_Field_t;

/**
 * @brief   Describes a Pin identifier Type.
 */
typedef struct _Gpio_ll_Pin_t
{
   Gpio_ll_Port_t port;
   Gpio_ll_Field_t field;
} Gpio_ll_Pin_t;

/**
 * @brief   Creates a pin identifier which can be mapped to a pin constant.
 * @details The encoding of this constant is platform specific.
 */
#define Gpio_ll_Map(port, field) ((Gpio_ll_Pin_t){ (port), (field) })

/**
 * @brief   Decodes port from a pin identifier.
 */
#define Gpio_ll_GetPinPort(x)       ((x).port)

/**
 * @brief   Decodes field from a pin identifier.
 */
#define Gpio_ll_GetPinField(x)        ((x).field)

/**
 * @brief   Pin constants that are mapped to their respective pin identifier.
 */
#define GPIO_LL_PIN_A0        Gpio_ll_Map(GPIOA, 0)
#define GPIO_LL_PIN_A1        Gpio_ll_Map(GPIOA, 1)
#define GPIO_LL_PIN_A2        Gpio_ll_Map(GPIOA, 2)
#define GPIO_LL_PIN_A3        Gpio_ll_Map(GPIOA, 3)
#define GPIO_LL_PIN_A4        Gpio_ll_Map(GPIOA, 4)
#define GPIO_LL_PIN_A5        Gpio_ll_Map(GPIOA, 5)
#define GPIO_LL_PIN_A6        Gpio_ll_Map(GPIOA, 6)
#define GPIO_LL_PIN_A7        Gpio_ll_Map(GPIOA, 7)
#define GPIO_LL_PIN_A8        Gpio_ll_Map(GPIOA, 8)
#define GPIO_LL_PIN_A9        Gpio_ll_Map(GPIOA, 9)
#define GPIO_LL_PIN_A10       Gpio_ll_Map(GPIOA, 10)
#define GPIO_LL_PIN_A11       Gpio_ll_Map(GPIOA, 11)
#define GPIO_LL_PIN_A12       Gpio_ll_Map(GPIOA, 12)
#define GPIO_LL_PIN_A13       Gpio_ll_Map(GPIOA, 13)
#define GPIO_LL_PIN_A14       Gpio_ll_Map(GPIOA, 14)
#define GPIO_LL_PIN_A15       Gpio_ll_Map(GPIOA, 15)

/**
 * @brief   Sets pin logical state to HIGH
 *
 * @param[in] port      port identifier
 * @param[in] field     field number within the port register
 *
 */
#define Gpio_ll_Set(port, field)   ( (port)->BSRR |= (1 << (field)) )

/**
 * @brief   Clears pin logical state to LOW
 *
 * @param[in] port      port identifier
 * @param[in] field     field number within the port register
 *
 */
#define Gpio_ll_Clr(port, field)   ( (port)->BRR |= (1 << (field) ) )

/**
 * @brief   Configures pin as an output
 *
 * @param[in] port      port identifier
 * @param[in] field     field number within the port register
 *
 */
#define Gpio_ll_AsOutput(port, field)                 \
{                                                     \
   (port)->MODER &= ~(3 << (2 * (field)));            \
   (port)->MODER |= (1 << (2 * (field)));             \
}                                                     \
#endif /* _GPIO_ll */