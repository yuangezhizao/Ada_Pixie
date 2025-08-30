#include "GMT154_07.h"

static const char* TAG = "MAIN-LGVL";

void app_main(void)
{
#if CONFIG_I2C_COMMUNICATION_METHOD_BUILTIN_RW || CONFIG_I2C_COMMUNICATION_METHOD_CALLBACK_RW

    // ESP_ERROR_CHECK(i2c_drv_init());

    ESP_LOGI(TAG, "I2C initialized successfully");

    // Run bus scan
    i2c_drv_scan();

#endif

    /* LCD HW initialization */
    ESP_ERROR_CHECK(app_lcd_init());

    /* LVGL initialization */
    ESP_ERROR_CHECK(app_lvgl_init());

    /* Show LVGL objects */
    app_main_display();
}
