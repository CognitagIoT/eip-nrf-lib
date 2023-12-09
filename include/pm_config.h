/**
 * @file
 * @brief Memory partitions from Devicetree instead of Nordic PM
 * @author Jordan Yates <jordan.yates@data61.csiro.au>
 * @copyright Commonwealth Scientific and Industrial Research Organisation, 2022
 * @spdxlicense EIP Common License
 *
 * @details
 * Nordic's Partition Manager (PM) generates this file from a yaml file description.
 * Because our devicetree files are more correct than upstream Zephyr due to snippets,
 * we can simply use the devicetree nodes to specify this information.
 */

#ifndef SDK_NRF_INCLUDE_PM_CONFIG_H_
#define SDK_NRF_INCLUDE_PM_CONFIG_H_

/* Includes ------------------------------------------------------------------*/

#include <zephyr/devicetree.h>
#include <zephyr/toolchain.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Module Defines ------------------------------------------------------------*/

#ifdef CONFIG_NRF_MODEM_LIB

#define MODEM_LIB_SRAM_NODE DT_NODELABEL(sram0_bsd)

#define PM_NRF_MODEM_LIB_SRAM_ADDRESS   DT_REG_ADDR(MODEM_LIB_SRAM_NODE)
#define PM_NRF_MODEM_LIB_SRAM_SIZE      DT_REG_SIZE(MODEM_LIB_SRAM_NODE)

#define PM_NRF_MODEM_LIB_TX_ADDRESS     PM_NRF_MODEM_LIB_SRAM_ADDRESS
#define PM_NRF_MODEM_LIB_RX_ADDRESS     (PM_NRF_MODEM_LIB_SRAM_ADDRESS + CONFIG_NRF_MODEM_LIB_SHMEM_TX_SIZE)
#define PM_NRF_MODEM_LIB_CTRL_ADDRESS   (PM_NRF_MODEM_LIB_RX_ADDRESS + CONFIG_NRF_MODEM_LIB_SHMEM_RX_SIZE)

#endif /* CONFIG_NRF_MODEM_LIB */

/*----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* SDK_NRF_INCLUDE_PM_CONFIG_H_ */
