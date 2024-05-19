/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * NXP Confidential. This software is owned or controlled by NXP and may only be
 * used strictly in accordance with the applicable license terms. By expressly
 * accepting such terms or by downloading, installing, activating and/or otherwise
 * using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms. If you do not agree to be
 * bound by the applicable license terms, then you may not retain, install,
 * activate or otherwise use the software. The production use license in
 * Section 2.3 is expressly granted for this software.
 */
/*!
** @file main.c
** @version 01.00
** @brief
**         Main module.
**         This module contains user's application code.
*/
/* MODULE main */

/* Including needed modules to compile this module/procedure */
#include "sdk_project_config.h"
#include "osif.h"
#include <stdio.h>


    #define TX_MAILBOX  (1UL)
    #define TX_MSG_ID   (0x123UL)
    #define RX_MAILBOX  (0UL)
    #define RX_MSG_ID   (0x124UL)


volatile int exit_code = 0;


static void can_init(void);


/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
*/
int main(void)
{
    /* Write your local variable definition here */
    ftm_state_t ftmStateStruct;
    ftm_state_t ftmStateStruct2;

    uint8_t ii;
    can_message_t recvMsg;

    uint16_t dutyCycle = flexTimer_pwm_1_IndependentChannelsConfig[0].uDutyCyclePercent;

    /* Initialize clock module */
    CLOCK_SYS_Init(g_clockManConfigsArr, CLOCK_MANAGER_CONFIG_CNT, g_clockManCallbacksArr, CLOCK_MANAGER_CALLBACK_CNT);
    CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);

    /* Initialize pins */
    PINS_DRV_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

    /* Initialize FTM instance */
    FTM_DRV_Init(INST_FLEXTIMER_PWM_1, &flexTimer_pwm_1_InitConfig, &ftmStateStruct);


    /* Initialize FTM instance */
    FTM_DRV_Init(INST_FLEXTIMER_PWM_2, &flexTimer_pwm_2_InitConfig, &ftmStateStruct2);

    /* Initialize FTM PWM channel */
    FTM_DRV_InitPwm(INST_FLEXTIMER_PWM_1, &flexTimer_pwm_1_PwmConfig);

    /* Initialize FTM PWM channel */
    FTM_DRV_InitPwm(INST_FLEXTIMER_PWM_2, &flexTimer_pwm_2_PwmConfig);

    can_init();

    for(ii=0;ii<6;ii++)
    {
		FTM_DRV_UpdatePwmChannel(INST_FLEXTIMER_PWM_2,
								 flexTimer_pwm_2_IndependentChannelsConfig[ii].hwChannelId,
								 FTM_PWM_UPDATE_IN_DUTY_CYCLE, 0x4000,
								 0U,
								 true);
    }


    /* Infinite loop */
    for ( ;; )
    {
        //dutyCycle += 50;
        if (dutyCycle > 0x4000U)
        {
            dutyCycle = 1U;
        }
        FTM_DRV_UpdatePwmChannel(INST_FLEXTIMER_PWM_1,
                                 flexTimer_pwm_1_IndependentChannelsConfig[0].hwChannelId,
                                 FTM_PWM_UPDATE_IN_DUTY_CYCLE, dutyCycle,
                                 0U,
                                 true);

        //can
        /* Define receive buffer */


        /* Start receiving data in RX_MAILBOX. */
        CAN_Receive(&can_instance0, RX_MAILBOX, &recvMsg);

        /* Wait until the previous FlexCAN receive is completed */
        while(CAN_GetTransferStatus(&can_instance0, RX_MAILBOX) == STATUS_BUSY);

        /* Check the received message ID and payload */
        if(recvMsg.data[0] == 0x11)
        {
        	dutyCycle+=50;
        }

        OSIF_TimeDelay(10);
    }

    return exit_code;
}


void can_init(void)
{

    can_buff_config_t buffCfg =  {
        .enableFD = false,
        .enableBRS = false,
        .fdPadding = 0U,
        .idType = CAN_MSG_ID_STD,
        .isRemote = false
    };

    CAN_Init(&can_instance0, &can_config0);

    /* Configure RX buffer with index RX_MAILBOX */
    CAN_ConfigRxBuff(&can_instance0, RX_MAILBOX, &buffCfg, RX_MSG_ID);
}


/* END main */
