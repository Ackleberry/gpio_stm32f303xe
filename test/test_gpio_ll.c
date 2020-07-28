/**
 * @file    test_gpio_ll.c
 * @author  Brooks Anderson
 * @date    07/27/2020
 * @brief   GPIO Driver Tests for STM32F303xE
 */

#include "unity.h"
#include "gpio_hal.h"

#define FLAG32(bit) (1UL << (bit))

void setUp(void)
{

}

void tearDown(void)
{
}

void test_GPIO_Set_ShouldSetOutputHigh(void)
{
   GPIOA->BSRR = 0;

   GPIO_Set(GPIO_LL_PIN_A0);

   TEST_ASSERT_EQUAL_HEX32(FLAG32(0), GPIOA->BSRR);

   GPIO_Set(GPIO_LL_PIN_A5);

   TEST_ASSERT_EQUAL_HEX32(FLAG32(0) | FLAG32(5), GPIOA->BSRR);

   GPIO_Set(GPIO_LL_PIN_A15);

   TEST_ASSERT_EQUAL_HEX32(FLAG32(0) | FLAG32(5) | FLAG32(15), GPIOA->BSRR);
}

void test_GPIO_Clr_ShouldClearOutputLow(void)
{
   GPIOA->BRR = 0;

   GPIO_Clr(GPIO_LL_PIN_A0);

   TEST_ASSERT_EQUAL_HEX32(FLAG32(0), GPIOA->BRR);

   GPIO_Clr(GPIO_LL_PIN_A5);

   TEST_ASSERT_EQUAL_HEX32((FLAG32(0) | FLAG32(5)), GPIOA->BRR);

   GPIO_Clr(GPIO_LL_PIN_A15);

   TEST_ASSERT_EQUAL_HEX32((FLAG32(0) | FLAG32(5) | FLAG32(15)), GPIOA->BRR);
}