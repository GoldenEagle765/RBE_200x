cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(red_light C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(red_light.c
  red_light
 )
 
 target_link_libraries(red_light.c 
 	pico_stdlib
 	)
 pico_add_extra_outputs(red_light.c)

