#include "unity.h"
#include "gpio.h"
#include "stm32f303xe.h"

#define BIT_TO_MASK(a) (1u << (a))

void setUp(void)
{

}

void tearDown(void)
{
}

void test_GPIO_Set_ShouldSetOutputHigh(void)
{
   GPIO[GPIO_PORT_A_IDX].ODR = 0;

   GPIO_Set(STM32F303_PIN_PA5);

   TEST_ASSERT_EQUAL_HEX32(BIT_TO_MASK(5), GPIO[GPIO_PORT_A_IDX].ODR);
}