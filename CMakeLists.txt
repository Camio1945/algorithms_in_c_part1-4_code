cmake_minimum_required(VERSION 3.0)
project(algorithms_in_c_part1-4_code)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -pedantic -Wno-implicit-int")

add_executable(temp temp.c)

add_executable(program_01_01.edited Chapter01/program_01_01.edited.c)

add_executable(program_01_01.original Chapter01/program_01_01.original.c)
