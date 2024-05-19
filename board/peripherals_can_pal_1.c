/***********************************************************************************************************************
 * This file was generated by the S32 Configuration Tools. Any manual edits made to this file
 * will be overwritten if the respective S32 Configuration Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Peripherals v10.0
processor: S32K116
package_id: S32K116_LQFP48
mcu_data: s32sdk_s32k1xx_rtm_403
processor_version: 0.0.0
functionalGroups:
- name: BOARD_InitPeripherals
  UUID: bf375e1f-983b-4c53-9f39-9a9b8e90e2ac
  called_from_default_init: true
  selectedCore: core0
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/*******************************************************************************
 * Included files 
 ******************************************************************************/
#include "peripherals_can_pal_1.h"

/*******************************************************************************
 * can_pal_1 initialization code
 ******************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'can_pal_1'
- type: 'can_pal_config'
- mode: 'general'
- custom_name_enabled: 'false'
- type_id: 'can_pal'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'CAN0'
- config_sets:
  - can_pal:
    - can_instance_t2:
      - name: 'can_instance0'
      - readonly: 'false'
      - instType: 'CAN_INST_TYPE_FLEXCAN'
    - can_user_config_t2:
      - name: 'can_config0'
      - readonly: 'false'
      - maxBuffNum: '16'
      - mode: 'CAN_NORMAL_MODE'
      - peClkSrc: 'CAN_CLK_SOURCE_PERIPH'
      - enableFD: 'false'
      - payloadSize: 'CAN_PAYLOAD_SIZE_8'
      - can_bitrate2ts: 'true'
      - flexcan_cfg_time_segments2:
        - nominalBitrate:
          - rJumpwidth: '0'
          - bitrate: '500'
          - samplingPoint: '0'
        - dataBitrate: []
    - can_fifo_ext2:
      - isRxFIFO_Enable: 'false'
      - name: 'can_fifo_ext0'
      - struct_extension:
        - readonly: 'false'
        - numIdFilters: 'FLEXCAN_RX_FIFO_ID_FILTERS_8'
        - idFormat: 'FLEXCAN_RX_FIFO_ID_FORMAT_A'
        - idFilterTable: 'NULL'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/**
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.7, External variable could be made static.
 * The external variables will be used in other source files in application code.
 *
 */

can_instance_t can_instance0 = {
  .instType = CAN_INST_TYPE_FLEXCAN,
  .instIdx = 0UL
};

can_user_config_t can_config0 = {
  .maxBuffNum = 16UL,
  .mode = CAN_NORMAL_MODE,
  .peClkSrc = CAN_CLK_SOURCE_PERIPH,
  .enableFD = false,
  .payloadSize = CAN_PAYLOAD_SIZE_8,
  .nominalBitrate = {
    .propSeg = 7UL,
    .phaseSeg1 = 4UL,
    .phaseSeg2 = 1UL,
    .preDivider = 4UL,
    .rJumpwidth = 0UL
  },
  .dataBitrate = {
    .propSeg = 7UL,
    .phaseSeg1 = 4UL,
    .phaseSeg2 = 1UL,
    .preDivider = 4UL,
    .rJumpwidth = 0UL
  },
  .extension = NULL
};

