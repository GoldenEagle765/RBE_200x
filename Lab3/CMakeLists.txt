cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(v_blink C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(v_blink
  v_blink.c
 )
 
 target_link_libraries(my_blink
 	pico_stdlib
 	hardware_gpio
 	hardware_adc
 	)
 pico_add_extra_outputs(v_blink.c)
