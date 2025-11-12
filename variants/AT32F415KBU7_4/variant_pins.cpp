/*
 * MIT License
 * Copyright (c) 2017 - 2022 _VIFEXTech
 *
 * Pin mapping for AT32F415KBU7-4 (LQFP32/QFN32 package)
 * Based on official AT32F415 datasheet pages 27-29
 *
 * Available GPIO: PA0-PA15, PB0-PB8, PD0-PD1
 * Total: 27 GPIO pins
 */

#include "gpio.h"

// Pin mapping for LQFP32/QFN32 package (verified from datasheet)
const PinInfo_TypeDef PIN_MAP[PIN_MAX] =
{
    // Port A (16 pins: PA0-PA15) - All available on LQFP32
    {GPIOA, TIM2,  ADC1, GPIO_Pin_0,  1, ADC_CHANNEL_0}, /* PA0  - Pin 6  - WKUP, ADC1_IN0, TIM2_CH1 */
    {GPIOA, TIM2,  ADC1, GPIO_Pin_1,  2, ADC_CHANNEL_1}, /* PA1  - Pin 7  - ADC1_IN1, TIM2_CH2, USART2_RTS */
    {GPIOA, TIM2,  ADC1, GPIO_Pin_2,  3, ADC_CHANNEL_2}, /* PA2  - Pin 8  - ADC1_IN2, TIM2_CH3, USART2_TX */
    {GPIOA, TIM2,  ADC1, GPIO_Pin_3,  4, ADC_CHANNEL_3}, /* PA3  - Pin 9  - ADC1_IN3, TIM2_CH4, USART2_RX */
    {GPIOA, NULL,  ADC1, GPIO_Pin_4,  0, ADC_CHANNEL_4}, /* PA4  - Pin 10 - ADC1_IN4, SPI1_NSS, USART2_CK */
    {GPIOA, NULL,  ADC1, GPIO_Pin_5,  0, ADC_CHANNEL_5}, /* PA5  - Pin 11 - ADC1_IN5, SPI1_SCK */
    {GPIOA, TIM3,  ADC1, GPIO_Pin_6,  1, ADC_CHANNEL_6}, /* PA6  - Pin 12 - ADC1_IN6, TIM3_CH1, SPI1_MISO */
    {GPIOA, TIM3,  ADC1, GPIO_Pin_7,  2, ADC_CHANNEL_7}, /* PA7  - Pin 13 - ADC1_IN7, TIM3_CH2, SPI1_MOSI */
    {GPIOA, TIM1,  NULL, GPIO_Pin_8,  1, ADC_CHANNEL_X}, /* PA8  - Pin 18 - TIM1_CH1, USART1_CK, CLKOUT */
    {GPIOA, TIM1,  NULL, GPIO_Pin_9,  2, ADC_CHANNEL_X}, /* PA9  - Pin 19 - TIM1_CH2, USART1_TX, OTG_FS_VBUS */
    {GPIOA, TIM1,  NULL, GPIO_Pin_10, 3, ADC_CHANNEL_X}, /* PA10 - Pin 20 - TIM1_CH3, USART1_RX, OTG_FS_ID */
    {GPIOA, TIM1,  NULL, GPIO_Pin_11, 4, ADC_CHANNEL_X}, /* PA11 - Pin 21 - TIM1_CH4, USART1_CTS, CAN_RX, OTG_FS_DM */
    {GPIOA, NULL,  NULL, GPIO_Pin_12, 0, ADC_CHANNEL_X}, /* PA12 - Pin 22 - CAN_TX, USART1_RTS, OTG_FS_DP */
    {GPIOA, NULL,  NULL, GPIO_Pin_13, 0, ADC_CHANNEL_X}, /* PA13 - Pin 23 - JTMS-SWDIO */
    {GPIOA, NULL,  NULL, GPIO_Pin_14, 0, ADC_CHANNEL_X}, /* PA14 - Pin 24 - JTCK-SWCLK */
    {GPIOA, TIM2,  NULL, GPIO_Pin_15, 1, ADC_CHANNEL_X}, /* PA15 - Pin 25 - JTDI, TIM2_CH1, SPI1_NSS */

    // Port B (9 pins: PB0-PB8) - Note: PB9 NOT available on LQFP32!
    {GPIOB, TIM3,  ADC1, GPIO_Pin_0,  3, ADC_CHANNEL_8}, /* PB0  - Pin 14 - ADC1_IN8, TIM3_CH3 */
    {GPIOB, TIM3,  ADC1, GPIO_Pin_1,  4, ADC_CHANNEL_9}, /* PB1  - Pin 15 - ADC1_IN9, TIM3_CH4 */
    {GPIOB, NULL,  NULL, GPIO_Pin_2,  0, ADC_CHANNEL_X}, /* PB2  - Pin 16 - BOOT1 */
    {GPIOB, TIM2,  NULL, GPIO_Pin_3,  2, ADC_CHANNEL_X}, /* PB3  - Pin 26 - JTDO, TRACESWO, TIM2_CH2, SPI1_SCK */
    {GPIOB, TIM3,  NULL, GPIO_Pin_4,  1, ADC_CHANNEL_X}, /* PB4  - Pin 27 - NJTRST, TIM3_CH1, SPI1_MISO */
    {GPIOB, TIM3,  NULL, GPIO_Pin_5,  2, ADC_CHANNEL_X}, /* PB5  - Pin 28 - TIM3_CH2, SPI1_MOSI, I2C1_SMBA */
    {GPIOB, TIM4,  NULL, GPIO_Pin_6,  1, ADC_CHANNEL_X}, /* PB6  - Pin 29 - TIM4_CH1, I2C1_SCL, USART1_TX */
    {GPIOB, TIM4,  NULL, GPIO_Pin_7,  2, ADC_CHANNEL_X}, /* PB7  - Pin 30 - TIM4_CH2, I2C1_SDA, USART1_RX */
    {GPIOB, TIM4,  NULL, GPIO_Pin_8,  3, ADC_CHANNEL_X}, /* PB8  - Pin 32 - TIM4_CH3, I2C1_SCL, CAN_RX */

    // Port D (2 pins: PD0-PD1)
    {GPIOD, NULL,  NULL, GPIO_Pin_0,  0, ADC_CHANNEL_X}, /* PD0  - Pin 2  - OSC_IN (can be reconfigured as GPIO) */
    {GPIOD, NULL,  NULL, GPIO_Pin_1,  0, ADC_CHANNEL_X}, /* PD1  - Pin 3  - OSC_OUT (can be reconfigured as GPIO) */
};
