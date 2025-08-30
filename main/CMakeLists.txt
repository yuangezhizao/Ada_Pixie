file(GLOB_RECURSE AUDIO_PROCESSOR_C_SOURCES ${CMAKE_SOURCE_DIR} "audio_processor/*.c")
file(GLOB_RECURSE COZE_CHAT_APP_C_SOURCES ${CMAKE_SOURCE_DIR} "coze_chat_app/*.c")
file(GLOB_RECURSE LVGL_C_SOURCES ${CMAKE_SOURCE_DIR} "lvgl/*.c")

idf_component_register(
    SRCS
    ${AUDIO_PROCESSOR_C_SOURCES}
    ${COZE_CHAT_APP_C_SOURCES}
    ${LVGL_C_SOURCES}
    # "main.c"
    # "main_coze_ws_app.c"
    "main_lvgl.c"

    INCLUDE_DIRS
    "."
    "audio_processor"
    "coze_chat_app"
    "lvgl"

    REQUIRES
)

if (NOT CONFIG_KEY_PRESS_DIALOG_MODE)
spiffs_create_partition_image(spiffs_data ../spiffs FLASH_IN_PROJECT)
endif()

lvgl_port_create_c_image("images/esp_logo.png" "images/" "ARGB8888" "NONE")
lvgl_port_add_images(${COMPONENT_LIB} "images/")
