/**
  ******************************************************************************
  * @file    usbd_hid.h
  * @author  MCD Application Team
  * @brief   Header file for the usbd_hid_core.c file.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2015 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                      http://www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USB_HID_H
#define __USB_HID_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include  "usbd_ioreq.h"

/** @addtogroup STM32_USB_DEVICE_LIBRARY
  * @{
  */

/** @defgroup USBD_HID
  * @brief This file is the Header file for usbd_hid.c
  * @{
  */


/** @defgroup USBD_HID_Exported_Defines
  * @{
  */

#define MSC_EPOUT_ADDR               0x01U
#define MSC_EPIN_ADDR                0x81U

#define HID_CMD_EPOUT_ADDR                0x02U
#define HID_CMD_EPIN_ADDR                 0x82U
#define HID_CMD_EPIN_SIZE                 64U
#define HID_CMD_EPOUT_SIZE                64U

#define HID_FIDO_EPOUT_ADDR                0x03U
#define HID_FIDO_EPIN_ADDR                 0x83U
#define HID_FIDO_EPIN_SIZE                 64U
#define HID_FIDO_EPOUT_SIZE                64U

enum usb_interfaces {
	INTERFACE_MSC,
	INTERFACE_CMD,
	INTERFACE_FIDO,
	INTERFACE_MAX
};

#define USB_HID_CONFIG_DESC_SIZ       (9 + \
				(9 + 7 + 7)*1 + \
				((9 + 9 + 7 + 7) * 2))

#define USB_HID_DESC_SIZ              9U

#define HID_DESCRIPTOR_TYPE           0x21U
#define HID_REPORT_DESC               0x22U

#ifndef HID_HS_BINTERVAL
#define HID_HS_BINTERVAL            0x07U
#endif /* HID_HS_BINTERVAL */

#ifndef HID_FS_BINTERVAL
#define HID_FS_BINTERVAL            0x0AU
#endif /* HID_FS_BINTERVAL */

#define HID_REQ_SET_PROTOCOL          0x0BU
#define HID_REQ_GET_PROTOCOL          0x03U

#define HID_REQ_SET_IDLE              0x0AU
#define HID_REQ_GET_IDLE              0x02U

#define HID_REQ_SET_REPORT            0x09U
#define HID_REQ_GET_REPORT            0x01U
/**
  * @}
  */

/** @defgroup USBD_CORE_Exported_TypesDefinitions
  * @{
  */
typedef enum {
	HID_IDLE = 0,
	HID_BUSY,
}
HID_StateTypeDef;


typedef struct {
	uint8_t rx_buffer[64];
	uint32_t             Protocol;
	uint32_t             IdleState;
	uint32_t             AltSetting;
	HID_StateTypeDef     state;
	uint8_t *tx_report;
}
USBD_HID_HandleTypeDef;
/**
  * @}
  */

#include "types.h"

void usb_send_bytes(int ep, const u8 *data, int length);

/** @defgroup USBD_CORE_Exported_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup USBD_CORE_Exported_Variables
  * @{
  */

extern USBD_ClassTypeDef  USBD_Multi;
#define USBD_MULTI_CLASS    &USBD_Multi
/**
  * @}
  */

/** @defgroup USB_CORE_Exported_Functions
  * @{
  */
uint8_t USBD_HID_SendReport (USBD_HandleTypeDef *pdev,
                             int interfaceNum,
                             uint8_t *report,
                             uint16_t len);

uint32_t USBD_HID_GetPollingInterval (USBD_HandleTypeDef *pdev);

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif  /* __USB_HID_H */
/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
