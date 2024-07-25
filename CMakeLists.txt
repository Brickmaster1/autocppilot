cmake_minimum_required(VERSION 3.12)

set(PICO_SDK_FETCH_FROM_GIT ON)

include(pico_sdk_import.cmake)
include(pico_extras_import_optional.cmake)

project(autocppilot C CXX ASM)
set(CMAKE_CXX_STANDARD 20)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.3.0")
    message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.3.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

pico_sdk_init()

add_executable(${PROJECT_NAME}
        src/main.cpp
)

pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)

# pull in common dependencies
target_link_libraries(${PROJECT_NAME} pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(${PROJECT_NAME})