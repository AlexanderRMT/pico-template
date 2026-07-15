cmake_minimum_required(VERSION 3.13)

# ===== Extension bootstrap block. Verbatim. Do not move. =====
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.3.0)
set(toolchainVersion 15_2_Rel1)
set(picotoolVersion 2.3.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# =============================================================

if(NOT DEFINED PICO_BOARD)
    set(PICO_BOARD pico CACHE STRING "Target board")
endif()
list(APPEND PICO_BOARD_HEADER_DIRS ${CMAKE_CURRENT_LIST_DIR}/boards)

include(pico_sdk_import.cmake)

project(pico_template C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

pico_sdk_init()

add_executable(${PROJECT_NAME} src/main.cpp)

# pico_generate_pio_header(${PROJECT_NAME} ${CMAKE_CURRENT_LIST_DIR}/src/foo.pio)

target_link_libraries(${PROJECT_NAME}
        pico_stdlib
        hardware_pio
        hardware_pwm
        hardware_dma
)

pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)

pico_add_extra_outputs(${PROJECT_NAME})   # .uf2 .bin .hex .map .dis

add_custom_target(flash
        COMMAND ${USERHOME}/.pico-sdk/picotool/${picotoolVersion}/picotool/picotool.exe
        load -f -x $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.uf2
        DEPENDS ${PROJECT_NAME}
        USES_TERMINAL)