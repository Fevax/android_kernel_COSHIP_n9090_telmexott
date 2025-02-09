
#ifndef __PLATFORM_PMM_H__
#define __PLATFORM_PMM_H__

struct mali_gpu_utilization_data;

typedef enum mali_power_mode
{
    MALI_POWER_MODE_ON  = 0x1,
    MALI_POWER_MODE_DEEP_SLEEP,
    MALI_POWER_MODE_LIGHT_SLEEP,
    //MALI_POWER_MODE_NUM
} mali_power_mode;

#ifdef CONFIG_MALI_DT

int mali_clk_enable(struct device *device);
int mali_clk_disable(struct device *device);

#endif

/** @brief Platform power management initialisation of MALI
 *
 * This is called from the entrypoint of the driver to initialize the platform
 *
 */
int mali_pmm_init(struct platform_device *device);

/** @brief Platform power management deinitialisation of MALI
 *
 * This is called on the exit of the driver to terminate the platform
 *
 */
void mali_pmm_deinit(struct platform_device *device);

/** @brief Platform power management mode change of MALI
 *
 * This is called on the power state transistion of MALI.
 * @param mode defines the power modes
 */
void mali_pmm_tri_mode(mali_power_mode mode);

/** @brief Platform power management specific GPU utilization handler
 *
 * When GPU utilization handler is enabled, this function will be
 * periodically called.
 *
 * @param utilization The Mali GPU's work loading from 0 ~ 256. 
 * 0 = no utilization, 256 = full utilization.
 */
void mali_pmm_utilization_handler(struct mali_gpu_utilization_data *data);

unsigned int gpu_get_current_utilization(void);

void mali_platform_power_mode_change(struct device *device,
				     mali_power_mode power_mode);
bool mtk_mfg_is_ready(void);
void dump_clk_state(void);


#endif

