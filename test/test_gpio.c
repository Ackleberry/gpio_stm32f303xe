#include "unity.h"
#include "gpio.h"

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

   GPIO_Set(STM32F303_PIN_PA0);

   TEST_ASSERT_EQUAL_HEX32(FLAG32(0), GPIOA->BSRR);

   GPIO_Set(STM32F303_PIN_PA5);

   TEST_ASSERT_EQUAL_HEX32(FLAG32(0) | FLAG32(5), GPIOA->BSRR);

   GPIO_Set(STM32F303_PIN_PA15);
   
   TEST_ASSERT_EQUAL_HEX32(FLAG32(0) | FLAG32(5) | FLAG32(15), GPIOA->BSRR);
}