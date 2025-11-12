/*
 * MIT License
 * Copyright (c) 2017 - 2022 _VIFEXTech
 *
 * AT32F415 Clock Configuration
 */

#include "at32f415_clock.h"

/**
 * @brief  Configure system clock to 150MHz
 * @note   Uses 8MHz external crystal (HEXT)
 *         PLL configuration: 8MHz / 2 * 37.5 = 150MHz
 *         For 144MHz alternative: 8MHz / 2 * 36 = 144MHz
 * @param  none
 * @retval none
 */
void system_clock_config(void)
{
    /* Reset CRM (Clock and Reset Management) */
    crm_reset();

    /* Configure flash wait states for 150MHz operation */
    flash_psr_set(FLASH_WAIT_CYCLE_4);

    /* Enable external high-speed crystal oscillator (HEXT) */
    crm_clock_source_enable(CRM_CLOCK_SOURCE_HEXT, TRUE);

    /* Wait until HEXT is stable */
    while(crm_hext_stable_wait() == ERROR)
    {
    }

    /* Configure PLL:
     * Source: HEXT / 2 = 4MHz
     * Multiplier: 37.5 (for 150MHz) or 36 (for 144MHz)
     * Output: 4MHz * 37.5 = 150MHz
     *
     * Note: AT32F415 supports fractional PLL multipliers
     * Use CRM_PLL_MULT_37_5 for 150MHz or CRM_PLL_MULT_36 for 144MHz
     */
#if F_CPU == 150000000L
    /* Try to use 150MHz if the macro is available */
    #ifdef CRM_PLL_MULT_37_5
        crm_pll_config(CRM_PLL_SOURCE_HEXT_DIV, CRM_PLL_MULT_37_5);
    #else
        /* Fall back to 144MHz if 37.5x multiplier not available */
        crm_pll_config(CRM_PLL_SOURCE_HEXT_DIV, CRM_PLL_MULT_36);
    #endif
#elif F_CPU == 144000000L
    crm_pll_config(CRM_PLL_SOURCE_HEXT_DIV, CRM_PLL_MULT_36);
#else
    /* Default to 144MHz for other frequencies */
    crm_pll_config(CRM_PLL_SOURCE_HEXT_DIV, CRM_PLL_MULT_36);
#endif

    /* Enable PLL */
    crm_clock_source_enable(CRM_CLOCK_SOURCE_PLL, TRUE);

    /* Wait until PLL is stable */
    while(crm_flag_get(CRM_PLL_STABLE_FLAG) != SET)
    {
    }

    /* Configure AHB clock divider (HCLK = SYSCLK) */
    crm_ahb_div_set(CRM_AHB_DIV_1);

    /* Configure APB2 clock divider (max 75MHz) */
    crm_apb2_div_set(CRM_APB2_DIV_2);

    /* Configure APB1 clock divider (max 75MHz) */
    crm_apb1_div_set(CRM_APB1_DIV_2);

    /* Enable auto step mode for smooth clock switching */
    crm_auto_step_mode_enable(TRUE);

    /* Switch system clock source to PLL */
    crm_sysclk_switch(CRM_SCLK_PLL);

    /* Wait until PLL is used as system clock source */
    while(crm_sysclk_switch_status_get() != CRM_SCLK_PLL)
    {
    }

    /* Disable auto step mode */
    crm_auto_step_mode_enable(FALSE);

    /* Update SystemCoreClock global variable */
    system_core_clock_update();
}
