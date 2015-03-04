cmake_minimum_required(VERSION 3.0)

project(blasted_city)

# currently only valid on FreeBSD 10.1
add_definitions("-std=c++11")
add_definitions("-Weverything -Werror -Wno-c++98-compat -Wno-missing-prototypes -Wno-padded")
add_definitions("-fno-exceptions -fno-rtti")
add_definitions("-isystem /usr/local/include")

add_subdirectory(src)
