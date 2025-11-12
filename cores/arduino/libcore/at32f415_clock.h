/*
 * MIT License
 * Copyright (c) 2017 - 2022 _VIFEXTech
 *
 * AT32F415 Clock Configuration
 * Maximum frequency: 150MHz
 */

#ifndef __AT32F415_CLOCK_H
#define __AT32F415_CLOCK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "at32f415.h"

/**
 * @brief  Configure system clock to 150MHz (or 144MHz for USB compatibility)
 * @note   The system clock is configured as follow:
 *         System clock (SCLK)   = HEXT / 2 * PLL_MULT
 *         System clock source   = PLL (HEXT)
 *         - HEXT                = 8MHz (external crystal)
 *         - SCLK                = 150MHz (or 144MHz if F_CPU=144000000L)
 *         - AHBDIV              = 1
 *         - AHBCLK              = 150MHz (or 144MHz)
 *         - APB2DIV             = 2
 *         - APB2CLK             = 75MHz (or 72MHz)
 *         - APB1DIV             = 2
 *         - APB1CLK             = 75MHz (or 72MHz)
 *         - PLL_MULT            = 37.5 for 150MHz, 36 for 144MHz
 *         - Flash wait cycles   = 4
 *
 * @warning If USB OTG is used with PLL clock source, the CPU frequency
 *          MUST be 48, 72, 96, 120, or 144 MHz (NOT 150MHz).
 *          Use F_CPU=144000000L in boards.txt for USB support.
 *
 * @param  none
 * @retval none
 */
void system_clock_config(void);

#ifdef __cplusplus
}
#endif

#endif /* __AT32F415_CLOCK_H */
