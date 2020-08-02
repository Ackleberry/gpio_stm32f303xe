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
 *          These constants should only be used to define project specific pin
 *          constants.
 *
 *          Example:         #define GPIO_GREEN_LED       GPIO_LL_PIN_A5
 *
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

#define GPIO_LL_PIN_B0        Gpio_ll_Map(GPIOB, 0)
#define GPIO_LL_PIN_B1        Gpio_ll_Map(GPIOB, 1)
#define GPIO_LL_PIN_B2        Gpio_ll_Map(GPIOB, 2)
#define GPIO_LL_PIN_B3        Gpio_ll_Map(GPIOB, 3)
#define GPIO_LL_PIN_B4        Gpio_ll_Map(GPIOB, 4)
#define GPIO_LL_PIN_B5        Gpio_ll_Map(GPIOB, 5)
#define GPIO_LL_PIN_B6        Gpio_ll_Map(GPIOB, 6)
#define GPIO_LL_PIN_B7        Gpio_ll_Map(GPIOB, 7)
#define GPIO_LL_PIN_B8        Gpio_ll_Map(GPIOB, 8)
#define GPIO_LL_PIN_B9        Gpio_ll_Map(GPIOB, 9)
#define GPIO_LL_PIN_B10       Gpio_ll_Map(GPIOB, 10)
#define GPIO_LL_PIN_B11       Gpio_ll_Map(GPIOB, 11)
#define GPIO_LL_PIN_B12       Gpio_ll_Map(GPIOB, 12)
#define GPIO_LL_PIN_B13       Gpio_ll_Map(GPIOB, 13)
#define GPIO_LL_PIN_B14       Gpio_ll_Map(GPIOB, 14)
#define GPIO_LL_PIN_B15       Gpio_ll_Map(GPIOB, 15)

#define GPIO_LL_PIN_C0        Gpio_ll_Map(GPIOC, 0)
#define GPIO_LL_PIN_C1        Gpio_ll_Map(GPIOC, 1)
#define GPIO_LL_PIN_C2        Gpio_ll_Map(GPIOC, 2)
#define GPIO_LL_PIN_C3        Gpio_ll_Map(GPIOC, 3)
#define GPIO_LL_PIN_C4        Gpio_ll_Map(GPIOC, 4)
#define GPIO_LL_PIN_C5        Gpio_ll_Map(GPIOC, 5)
#define GPIO_LL_PIN_C6        Gpio_ll_Map(GPIOC, 6)
#define GPIO_LL_PIN_C7        Gpio_ll_Map(GPIOC, 7)
#define GPIO_LL_PIN_C8        Gpio_ll_Map(GPIOC, 8)
#define GPIO_LL_PIN_C9        Gpio_ll_Map(GPIOC, 9)
#define GPIO_LL_PIN_C10       Gpio_ll_Map(GPIOC, 10)
#define GPIO_LL_PIN_C11       Gpio_ll_Map(GPIOC, 11)
#define GPIO_LL_PIN_C12       Gpio_ll_Map(GPIOC, 12)
#define GPIO_LL_PIN_C13       Gpio_ll_Map(GPIOC, 13)
#define GPIO_LL_PIN_C14       Gpio_ll_Map(GPIOC, 14)
#define GPIO_LL_PIN_C15       Gpio_ll_Map(GPIOC, 15)

#define GPIO_LL_PIN_D0        Gpio_ll_Map(GPIOD, 0)
#define GPIO_LL_PIN_D1        Gpio_ll_Map(GPIOD, 1)
#define GPIO_LL_PIN_D2        Gpio_ll_Map(GPIOD, 2)
#define GPIO_LL_PIN_D3        Gpio_ll_Map(GPIOD, 3)
#define GPIO_LL_PIN_D4        Gpio_ll_Map(GPIOD, 4)
#define GPIO_LL_PIN_D5        Gpio_ll_Map(GPIOD, 5)
#define GPIO_LL_PIN_D6        Gpio_ll_Map(GPIOD, 6)
#define GPIO_LL_PIN_D7        Gpio_ll_Map(GPIOD, 7)
#define GPIO_LL_PIN_D8        Gpio_ll_Map(GPIOD, 8)
#define GPIO_LL_PIN_D9        Gpio_ll_Map(GPIOD, 9)
#define GPIO_LL_PIN_D10       Gpio_ll_Map(GPIOD, 10)
#define GPIO_LL_PIN_D11       Gpio_ll_Map(GPIOD, 11)
#define GPIO_LL_PIN_D12       Gpio_ll_Map(GPIOD, 12)
#define GPIO_LL_PIN_D13       Gpio_ll_Map(GPIOD, 13)
#define GPIO_LL_PIN_D14       Gpio_ll_Map(GPIOD, 14)
#define GPIO_LL_PIN_D15       Gpio_ll_Map(GPIOD, 15)

#define GPIO_LL_PIN_E0        Gpio_ll_Map(GPIOE, 0)
#define GPIO_LL_PIN_E1        Gpio_ll_Map(GPIOE, 1)
#define GPIO_LL_PIN_E2        Gpio_ll_Map(GPIOE, 2)
#define GPIO_LL_PIN_E3        Gpio_ll_Map(GPIOE, 3)
#define GPIO_LL_PIN_E4        Gpio_ll_Map(GPIOE, 4)
#define GPIO_LL_PIN_E5        Gpio_ll_Map(GPIOE, 5)
#define GPIO_LL_PIN_E6        Gpio_ll_Map(GPIOE, 6)
#define GPIO_LL_PIN_E7        Gpio_ll_Map(GPIOE, 7)
#define GPIO_LL_PIN_E8        Gpio_ll_Map(GPIOE, 8)
#define GPIO_LL_PIN_E9        Gpio_ll_Map(GPIOE, 9)
#define GPIO_LL_PIN_E10       Gpio_ll_Map(GPIOE, 10)
#define GPIO_LL_PIN_E11       Gpio_ll_Map(GPIOE, 11)
#define GPIO_LL_PIN_E12       Gpio_ll_Map(GPIOE, 12)
#define GPIO_LL_PIN_E13       Gpio_ll_Map(GPIOE, 13)
#define GPIO_LL_PIN_E14       Gpio_ll_Map(GPIOE, 14)
#define GPIO_LL_PIN_E15       Gpio_ll_Map(GPIOE, 15)

#define GPIO_LL_PIN_F0        Gpio_ll_Map(GPIOF, 0)
#define GPIO_LL_PIN_F1        Gpio_ll_Map(GPIOF, 1)
#define GPIO_LL_PIN_F2        Gpio_ll_Map(GPIOF, 2)
#define GPIO_LL_PIN_F3        Gpio_ll_Map(GPIOF, 3)
#define GPIO_LL_PIN_F4        Gpio_ll_Map(GPIOF, 4)
#define GPIO_LL_PIN_F5        Gpio_ll_Map(GPIOF, 5)
#define GPIO_LL_PIN_F6        Gpio_ll_Map(GPIOF, 6)
#define GPIO_LL_PIN_F7        Gpio_ll_Map(GPIOF, 7)
#define GPIO_LL_PIN_F8        Gpio_ll_Map(GPIOF, 8)
#define GPIO_LL_PIN_F9        Gpio_ll_Map(GPIOF, 9)
#define GPIO_LL_PIN_F10       Gpio_ll_Map(GPIOF, 10)
#define GPIO_LL_PIN_F11       Gpio_ll_Map(GPIOF, 11)
#define GPIO_LL_PIN_F12       Gpio_ll_Map(GPIOF, 12)
#define GPIO_LL_PIN_F13       Gpio_ll_Map(GPIOF, 13)
#define GPIO_LL_PIN_F14       Gpio_ll_Map(GPIOF, 14)
#define GPIO_LL_PIN_F15       Gpio_ll_Map(GPIOF, 15)

#define GPIO_LL_PIN_G0        Gpio_ll_Map(GPIOG, 0)
#define GPIO_LL_PIN_G1        Gpio_ll_Map(GPIOG, 1)
#define GPIO_LL_PIN_G2        Gpio_ll_Map(GPIOG, 2)
#define GPIO_LL_PIN_G3        Gpio_ll_Map(GPIOG, 3)
#define GPIO_LL_PIN_G4        Gpio_ll_Map(GPIOG, 4)
#define GPIO_LL_PIN_G5        Gpio_ll_Map(GPIOG, 5)
#define GPIO_LL_PIN_G6        Gpio_ll_Map(GPIOG, 6)
#define GPIO_LL_PIN_G7        Gpio_ll_Map(GPIOG, 7)
#define GPIO_LL_PIN_G8        Gpio_ll_Map(GPIOG, 8)
#define GPIO_LL_PIN_G9        Gpio_ll_Map(GPIOG, 9)
#define GPIO_LL_PIN_G10       Gpio_ll_Map(GPIOG, 10)
#define GPIO_LL_PIN_G11       Gpio_ll_Map(GPIOG, 11)
#define GPIO_LL_PIN_G12       Gpio_ll_Map(GPIOG, 12)
#define GPIO_LL_PIN_G13       Gpio_ll_Map(GPIOG, 13)
#define GPIO_LL_PIN_G14       Gpio_ll_Map(GPIOG, 14)
#define GPIO_LL_PIN_G15       Gpio_ll_Map(GPIOG, 15)

#define GPIO_LL_PIN_H0        Gpio_ll_Map(GPIOH, 0)
#define GPIO_LL_PIN_H1        Gpio_ll_Map(GPIOH, 1)
#define GPIO_LL_PIN_H2        Gpio_ll_Map(GPIOH, 2)
#define GPIO_LL_PIN_H3        Gpio_ll_Map(GPIOH, 3)
#define GPIO_LL_PIN_H4        Gpio_ll_Map(GPIOH, 4)
#define GPIO_LL_PIN_H5        Gpio_ll_Map(GPIOH, 5)
#define GPIO_LL_PIN_H6        Gpio_ll_Map(GPIOH, 6)
#define GPIO_LL_PIN_H7        Gpio_ll_Map(GPIOH, 7)
#define GPIO_LL_PIN_H8        Gpio_ll_Map(GPIOH, 8)
#define GPIO_LL_PIN_H9        Gpio_ll_Map(GPIOH, 9)
#define GPIO_LL_PIN_H10       Gpio_ll_Map(GPIOH, 10)
#define GPIO_LL_PIN_H11       Gpio_ll_Map(GPIOH, 11)
#define GPIO_LL_PIN_H12       Gpio_ll_Map(GPIOH, 12)
#define GPIO_LL_PIN_H13       Gpio_ll_Map(GPIOH, 13)
#define GPIO_LL_PIN_H14       Gpio_ll_Map(GPIOH, 14)
#define GPIO_LL_PIN_H15       Gpio_ll_Map(GPIOH, 15)

/**
 * @brief   Sets pin logical state to HIGH
 *
 * @param[in] port      port identifier
 * @param[in] field     pin field within the port register
 *
 */
#define Gpio_ll_Set(port, field)   ( (port)->BSRR |= (1 << (field)) )

/**
 * @brief   Clears pin logical state to LOW
 *
 * @param[in] port      port identifier
 * @param[in] field     pin field within the port register
 *
 */
#define Gpio_ll_Clear(port, field)   ( (port)->BRR |= (1 << (field) ) )

/**
 * @brief   Toggles the pin logical state.
 *
 * @param[in] port      port identifier
 * @param[in] field     pin field within the port register
 *
 */
#define Gpio_ll_Toggle(port, field)   ( (port)->ODR ^= (1 << (field) ) )

/**
 * @brief   Configures pin as a push pull output
 *
 * @param[in] port      port identifier
 * @param[in] field     pin field within the port register
 *
 */
#define Gpio_ll_AsOutput(port, field) \
{ \
   (port)->OTYPER &= ~(1 << (field)); \
   (port)->MODER &= ~(3 << (2 * (field))); \
   (port)->MODER |= (1 << (2 * (field))); \
} \

/**
 * @brief   Determines if the pin is set high. Evaluates to true or false.
 *
 * @param[in] port      port identifier
 * @param[in] field     pin field within the port register
 *
 */
#define Gpio_ll_IsSet(port, field)   ( ((port)->IDR & (1 << (field))) )

#endif /* _GPIO_ll */