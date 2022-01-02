cmake_minimum_required(VERSION 3.0)
project(algorithms_in_c_part1-4_code)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -pedantic -Wno-implicit-int")

add_executable(temp temp.c)

add_executable(program_01_01.edited Chapter01/program_01_01.edited.c)

add_executable(program_01_01.original Chapter01/program_01_01.original.c)

add_executable(program_01_02.original Chapter01/program_01_02.original.c)

add_executable(program_01_02.edited Chapter01/program_01_02.edited.c)

add_executable(program_01_02.test Chapter01/program_01_02.test.c)

add_executable(program_01_03.original Chapter01/program_01_03.original.c)

add_executable(program_01_03.edited Chapter01/program_01_03.edited.c)

add_executable(program_01_03.test Chapter01/program_01_03.test.c)

add_executable(program_01_04.test Chapter01/program_01_04.test1.c)

add_executable(program_01_04.edited Chapter01/program_01_04.edited.c)

add_executable(program_01_04.test1 Chapter01/program_01_04.test1.c)

add_executable(program_01_04.test2 Chapter01/program_01_04.test2.c)
