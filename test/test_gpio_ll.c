/**
 * @file    test_gpio_ll.c
 * @author  Brooks Anderson
 * @date    07/27/2020
 * @brief   GPIO Driver Tests for STM32F303xE
 */
#include <stdio.h>
#include "unity.h"
#include "gpio_hal.h"

#define FLAG32(bit) (1UL << (bit))

void setUp(void)
{

}

void tearDown(void)
{

}

void test_Gpio_Set_Should_SetOutputHigh(void)
{
   GPIOA->BSRR = 0;
   Gpio_Set(GPIO_LL_PIN_A0);

   TEST_ASSERT_EQUAL_HEX32(FLAG32(0), GPIOA->BSRR);

   Gpio_Set(GPIO_LL_PIN_A5);

   TEST_ASSERT_EQUAL_HEX32(FLAG32(0) | FLAG32(5), GPIOA->BSRR);

   Gpio_Set(GPIO_LL_PIN_A15);

   TEST_ASSERT_EQUAL_HEX32(FLAG32(0) | FLAG32(5) | FLAG32(15), GPIOA->BSRR);
}

void test_Gpio_Clr_Should_ClearOutputLow(void)
{
   GPIOA->BRR = 0;
   Gpio_Clr(GPIO_LL_PIN_A0);

   TEST_ASSERT_EQUAL_HEX32(FLAG32(0), GPIOA->BRR);

   Gpio_Clr(GPIO_LL_PIN_A5);

   TEST_ASSERT_EQUAL_HEX32((FLAG32(0) | FLAG32(5)), GPIOA->BRR);

   Gpio_Clr(GPIO_LL_PIN_A15);

   TEST_ASSERT_EQUAL_HEX32((FLAG32(0) | FLAG32(5) | FLAG32(15)), GPIOA->BRR);
}

void test_Gpio_AsOutput_Should_ConfigurePinIntoOutputMode(void)
{
   GPIOA->MODER = 0x00000000;
   Gpio_AsOutput(GPIO_LL_PIN_A0);

   TEST_ASSERT_EQUAL_HEX32(0x00000001, GPIOA->MODER);

   Gpio_AsOutput(GPIO_LL_PIN_A15);

   TEST_ASSERT_EQUAL_HEX32(0x40000001, GPIOA->MODER);

   GPIOA->MODER = 0xFFFFFFFF;
   Gpio_AsOutput(GPIO_LL_PIN_A0);

   TEST_ASSERT_EQUAL_HEX32(0xFFFFFFFD, GPIOA->MODER);

   Gpio_AsOutput(GPIO_LL_PIN_A15);

   TEST_ASSERT_EQUAL_HEX32(0x7FFFFFFD, GPIOA->MODER);
}