#ifndef __STM32F303xE_H
#define __STM32F303xE_H

#include <stdint.h>

/**
  * @brief General Purpose I/O
  */
typedef struct _GPIO_TypeDef
{
  volatile uint32_t MODER;        /*!< GPIO port mode register,               Address offset: 0x00      */
  volatile uint32_t OTYPER;       /*!< GPIO port output type register,        Address offset: 0x04      */
  volatile uint32_t OSPEEDR;      /*!< GPIO port output speed register,       Address offset: 0x08      */
  volatile uint32_t PUPDR;        /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
  volatile uint32_t IDR;          /*!< GPIO port input data register,         Address offset: 0x10      */
  volatile uint32_t ODR;          /*!< GPIO port output data register,        Address offset: 0x14      */
  volatile uint32_t BSRR;         /*!< GPIO port bit set/reset register,      Address offset: 0x1A      */
  volatile uint32_t LCKR;         /*!< GPIO port configuration lock register, Address offset: 0x1C      */
  volatile uint32_t AFR[2];       /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
  volatile uint32_t BRR;          /*!< GPIO bit reset register,               Address offset: 0x28      */
} GPIO_TypeDef;

/*!< AHB2 peripherals */
#ifdef TEST
    GPIO_TypeDef GPIOA_BASE;
    GPIO_TypeDef GPIOB_BASE;
    GPIO_TypeDef GPIOC_BASE;
    GPIO_TypeDef GPIOD_BASE;
    GPIO_TypeDef GPIOE_BASE;
    GPIO_TypeDef GPIOF_BASE;
    GPIO_TypeDef GPIOG_BASE;
    GPIO_TypeDef GPIOH_BASE;
#else
#   define GPIOA_BASE            (AHB2PERIPH_BASE + 0x00000000UL)
#   define GPIOB_BASE            (AHB2PERIPH_BASE + 0x00000400UL)
#   define GPIOC_BASE            (AHB2PERIPH_BASE + 0x00000800UL)
#   define GPIOD_BASE            (AHB2PERIPH_BASE + 0x00000C00UL)
#   define GPIOE_BASE            (AHB2PERIPH_BASE + 0x00001000UL)
#   define GPIOF_BASE            (AHB2PERIPH_BASE + 0x00001400UL)
#   define GPIOG_BASE            (AHB2PERIPH_BASE + 0x00001800UL)
#   define GPIOH_BASE            (AHB2PERIPH_BASE + 0x00001C00UL)
#endif

#ifdef TEST
#   define GPIOA               ((GPIO_TypeDef *) &GPIOA_BASE)
#   define GPIOB               ((GPIO_TypeDef *) &GPIOB_BASE)
#   define GPIOC               ((GPIO_TypeDef *) &GPIOC_BASE)
#   define GPIOD               ((GPIO_TypeDef *) &GPIOD_BASE)
#   define GPIOE               ((GPIO_TypeDef *) &GPIOE_BASE)
#   define GPIOF               ((GPIO_TypeDef *) &GPIOF_BASE)
#   define GPIOG               ((GPIO_TypeDef *) &GPIOG_BASE)
#   define GPIOH               ((GPIO_TypeDef *) &GPIOH_BASE)
#else
#   define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)
#   define GPIOB               ((GPIO_TypeDef *) GPIOB_BASE)
#   define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)
#   define GPIOD               ((GPIO_TypeDef *) GPIOD_BASE)
#   define GPIOE               ((GPIO_TypeDef *) GPIOE_BASE)
#   define GPIOF               ((GPIO_TypeDef *) GPIOF_BASE)
#   define GPIOG               ((GPIO_TypeDef *) GPIOG_BASE)
#   define GPIOH               ((GPIO_TypeDef *) GPIOH_BASE)
#endif

#endif /* __STM32F303xE_H */