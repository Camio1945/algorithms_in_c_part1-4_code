cmake_minimum_required(VERSION 3.0)
project(algorithms_in_c_part1-4_code)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -pedantic -Wno-implicit-int")

add_executable(temp temp.c)

add_executable(program_01_01.edited Chapter01/program_01_01/program_01_01.edited.c)
add_executable(program_01_01.original Chapter01/program_01_01/program_01_01.original.c)

add_executable(program_01_02.edited Chapter01/program_01_02/program_01_02.edited.c)
add_executable(program_01_02.original Chapter01/program_01_02/program_01_02.original.c)
add_executable(program_01_02.test Chapter01/program_01_02/program_01_02.test.c)

add_executable(program_01_03.edited Chapter01/program_01_03/program_01_03.edited.c)
add_executable(program_01_03.original Chapter01/program_01_03/program_01_03.original.c)
add_executable(program_01_03.test Chapter01/program_01_03/program_01_03.test.c)

add_executable(program_01_04.edited Chapter01/program_01_04/program_01_04.edited.c)
add_executable(program_01_04.original Chapter01/program_01_04/program_01_04.original.c)
add_executable(program_01_04.test Chapter01/program_01_04/program_01_04.test.c)


add_executable(program_02_01.edited Chapter02/program_02_01/program_02_01.edited.c)

add_executable(program_02_02.edited Chapter02/program_02_02/program_02_02.edited.c)

add_executable(program_02_02.test Chapter02/program_02_02/program_02_02.test.c)

add_executable(program_03_01.original Chapter03/program_03_01/program_03_01.original.c)

add_executable(program_03_01.edited Chapter03/program_03_01/program_03_01.edited.c)

add_executable(program_03_02.original Chapter03/program_03_02/program_03_02.original.c)

add_executable(program_03_02.edited Chapter03/program_03_02/program_03_02.edited.c)

add_executable(program_03_04.edited Chapter03/program_03_03-03_04/program_03_04.edited.c)
