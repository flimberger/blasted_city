cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

cmake_policy(SET CMP0072 NEW)

list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

project(BlastedCity)

include(bcCompileOptions)

add_subdirectory(src)
