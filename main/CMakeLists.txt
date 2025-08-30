file(GLOB_RECURSE AUDIO_PROCESSOR_C_SOURCES ${CMAKE_SOURCE_DIR} "audio_processor/*.c")
file(GLOB_RECURSE COZE_CHAT_APP_C_SOURCES ${CMAKE_SOURCE_DIR} "coze_chat_app/*.c")

idf_component_register(
    SRCS
    ${AUDIO_PROCESSOR_C_SOURCES}
    ${COZE_CHAT_APP_C_SOURCES}
    # "main.c"
    "main_coze_ws_app.c"

    INCLUDE_DIRS
    "."
    "audio_processor"
    "coze_chat_app"

    REQUIRES
)

if (NOT CONFIG_KEY_PRESS_DIALOG_MODE)
spiffs_create_partition_image(spiffs_data ../spiffs FLASH_IN_PROJECT)
endif()
