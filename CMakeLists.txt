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

add_executable(program_03_05 Chapter03/program_03_05/program_03_05.edited.c)

add_executable(program_03_05.edited Chapter03/program_03_05/program_03_05.edited.c)

add_executable(program_03_06.edited Chapter03/program_03_06/program_03_06.edited.c)

add_executable(program_03_07.edited Chapter03/program_03_07/program_03_07.edited.c)

add_executable(program_03_08.edited Chapter03/program_03_08/program_03_08.edited.c)

add_executable(program_03_09.edited Chapter03/program_03_09/program_03_09.edited.c)

add_executable(program_03_10.edited Chapter03/program_03_10/program_03_10.edited.c)

add_executable(program_03_11.edited Chapter03/program_03_11/program_03_11.edited.c)

add_executable(program_03_13.edited Chapter03/program_03_12-03_13-03_14/program_03_13.edited.c)

add_executable(program_03_15.edited Chapter03/program_03_15/program_03_15.edited.c)

add_executable(program_03_16.edited Chapter03/program_03_16/program_03_16.edited.c)

add_executable(program_03_17.edited Chapter03/program_03_17/program_03_17.edited.c)

add_executable(program_03_18.edited Chapter03/program_03_18/program_03_18.edited.c)

add_executable(program_03_19.edited Chapter03/program_03_19/program_03_19.edited.c)

add_executable(program_03_20.edited Chapter03/program_03_20/program_03_20.edited.c)

add_executable(program_03_30.test Chapter03/program_03_20/program_03_30.test.c)

add_executable(program_04_02.edited Chapter04/program_04_01-04_02-04_04-04_05/program_04_02.edited.c)

add_executable(program_04_03.edited Chapter04/program_04_03/program_04_03.edited.c)

add_executable(program_04_07.edited Chapter04/program_04_06-04_07-04_08/program_04_07.edited.c)

add_executable(program_04_10.edited Chapter04/program_04_09-04_10-04_11/program_04_10.edited.c)

add_executable(program_04_11.edited Chapter04/program_04_09-04_10-04_11/program_04_11.edited.c)
