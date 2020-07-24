#include "unity.h"
#include "gpio.h"

#define BIT_TO_MASK(a) (1u << (a))

void setUp(void)
{

}

void tearDown(void)
{
}

void test_GPIO_Set_ShouldSetOutputHigh(void)
{
   GPIOA->BSRR = 0;

   GPIO_Set(STM32F303_PIN_PA0);

   TEST_ASSERT_EQUAL_HEX32(BIT_TO_MASK(0), GPIOA->BSRR);

   GPIO_Set(STM32F303_PIN_PA5);

   TEST_ASSERT_EQUAL_HEX32(BIT_TO_MASK(0) | BIT_TO_MASK(5), GPIOA->BSRR);

   GPIO_Set(STM32F303_PIN_PA15);
   
   TEST_ASSERT_EQUAL_HEX32(BIT_TO_MASK(0) | BIT_TO_MASK(5) | BIT_TO_MASK(15), GPIOA->BSRR);
}