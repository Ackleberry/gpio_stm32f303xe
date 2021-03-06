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

void test_Gpio_Set_Should_SetPinOutputHigh(void)
{
   GPIOA->BSRR = 0;
   Gpio_Set(GPIO_LL_PIN_A0);

   TEST_ASSERT_EQUAL_HEX32(FLAG32(0), GPIOA->BSRR);

   Gpio_Set(GPIO_LL_PIN_A5);

   TEST_ASSERT_EQUAL_HEX32(FLAG32(0) | FLAG32(5), GPIOA->BSRR);

   Gpio_Set(GPIO_LL_PIN_A15);

   TEST_ASSERT_EQUAL_HEX32(FLAG32(0) | FLAG32(5) | FLAG32(15), GPIOA->BSRR);
}

void test_Gpio_Clear_Should_ClearPinOutputLow(void)
{
   GPIOA->BRR = 0;
   Gpio_Clear(GPIO_LL_PIN_A0);

   TEST_ASSERT_EQUAL_HEX32(FLAG32(0), GPIOA->BRR);

   Gpio_Clear(GPIO_LL_PIN_A5);

   TEST_ASSERT_EQUAL_HEX32((FLAG32(0) | FLAG32(5)), GPIOA->BRR);

   Gpio_Clear(GPIO_LL_PIN_A15);

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

void test_Gpio_AsOutput_Should_DefaultToPushPullConfiguration(void)
{
   // Start with pins in open drain configuration.
   GPIOA->OTYPER = 0x0000FFFF;
   Gpio_AsOutput(GPIO_LL_PIN_A0);

   TEST_ASSERT_EQUAL_HEX32(0x0000FFFE, GPIOA->OTYPER);

   Gpio_AsOutput(GPIO_LL_PIN_A15);

   TEST_ASSERT_EQUAL_HEX32(0x00007FFE, GPIOA->OTYPER);
}

void test_Gpio_Toggle_Should_TogglePinOutput(void)
{
   // From HIGH to LOW
   GPIOA->ODR = 0x0000FFFF;
   Gpio_Toggle(GPIO_LL_PIN_A0);
   TEST_ASSERT_EQUAL_HEX32(0x0000FFFE, GPIOA->ODR);
   Gpio_Toggle(GPIO_LL_PIN_A15);
   TEST_ASSERT_EQUAL_HEX32(0x00007FFE, GPIOA->ODR);

   // From LOW to HIGH
   GPIOA->ODR = 0x00000000;
   Gpio_Toggle(GPIO_LL_PIN_A0);
   TEST_ASSERT_EQUAL_HEX32(0x00000001, GPIOA->ODR);
   Gpio_Toggle(GPIO_LL_PIN_A15);
   TEST_ASSERT_EQUAL_HEX32(0x00008001, GPIOA->ODR);
}

void test_Gpio_IsSet_Should_ReturnTrueIfPinIsHigh(void)
{
   // Fake GPIO Input register data
   GPIOA->IDR = 0x0000F731;

   TEST_ASSERT_TRUE(Gpio_IsSet(GPIO_LL_PIN_A0));

   TEST_ASSERT_TRUE(Gpio_IsSet(GPIO_LL_PIN_A4));
   TEST_ASSERT_TRUE(Gpio_IsSet(GPIO_LL_PIN_A5));

   TEST_ASSERT_TRUE(Gpio_IsSet(GPIO_LL_PIN_A8));
   TEST_ASSERT_TRUE(Gpio_IsSet(GPIO_LL_PIN_A9));
   TEST_ASSERT_TRUE(Gpio_IsSet(GPIO_LL_PIN_A10));

   TEST_ASSERT_TRUE(Gpio_IsSet(GPIO_LL_PIN_A12));
   TEST_ASSERT_TRUE(Gpio_IsSet(GPIO_LL_PIN_A13));
   TEST_ASSERT_TRUE(Gpio_IsSet(GPIO_LL_PIN_A14));
   TEST_ASSERT_TRUE(Gpio_IsSet(GPIO_LL_PIN_A15));
}

void test_Gpio_IsSet_Should_ReturnFalseIfPinIsLow(void)
{
   // Fake GPIO Input register data
   GPIOA->IDR = 0x0000F731;

   TEST_ASSERT_FALSE(Gpio_IsSet(GPIO_LL_PIN_A1));
   TEST_ASSERT_FALSE(Gpio_IsSet(GPIO_LL_PIN_A2));
   TEST_ASSERT_FALSE(Gpio_IsSet(GPIO_LL_PIN_A3));

   TEST_ASSERT_FALSE(Gpio_IsSet(GPIO_LL_PIN_A6));
   TEST_ASSERT_FALSE(Gpio_IsSet(GPIO_LL_PIN_A7));

   TEST_ASSERT_FALSE(Gpio_IsSet(GPIO_LL_PIN_A11));
}

void test_Gpio_AsInput_Should_ConfigurePinToInputMode(void)
{
   GPIOA->MODER = 0xFFFFFFFF;
   Gpio_AsInput(GPIO_LL_PIN_A0);

   TEST_ASSERT_EQUAL_HEX32(0xFFFFFFFC, GPIOA->MODER);

   Gpio_AsInput(GPIO_LL_PIN_A15);

   TEST_ASSERT_EQUAL_HEX32(0x3FFFFFFC, GPIOA->MODER);
}

void test_Gpio_AsInput_Should_DefaultToNoPullUpPullDown(void)
{
   // Start with pins in open drain configuration.
   GPIOA->PUPDR = 0xFFFFFFFF;
   Gpio_AsInput(GPIO_LL_PIN_A0);

   TEST_ASSERT_EQUAL_HEX32(0xFFFFFFFE, GPIOA->PUPDR);

   Gpio_AsInput(GPIO_LL_PIN_A15);

   TEST_ASSERT_EQUAL_HEX32(0xFFFF7FFE, GPIOA->PUPDR);
}