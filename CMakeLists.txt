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

add_executable(program_04_12.edited Chapter04/program_04_12/program_04_12.edited.c)

add_executable(program_04_13.edited Chapter04/program_04_13-04_14-04_15/program_04_13.edited.c)

add_executable(program_04_17.edited Chapter04/program_04_16-04_17/program_04_17.edited.c)

add_executable(program_04_19.edited Chapter04/program_04_18-04_19-04_20/program_04_19.edited.c)

add_executable(program_04_21.edited Chapter04/program_04_21-04_22-04_23/program_04_21.edited.c)

add_executable(program_05_01.edited Chapter05/program_05_01/program_05_01.edited.c)

add_executable(program_05_02.edited Chapter05/program_05_02/program_05_02.edited.c)

add_executable(program_05_03.edited Chapter05/program_05_03/program_05_03.edited.c)

add_executable(program_05_04.edited Chapter05/program_05_04/program_05_04.edited.c)

add_executable(program_05_05.edited Chapter05/program_05_05/program_05_05.edited.c)

add_executable(program_05_06.edited Chapter05/program_05_06/program_05_06.edited.c)

add_executable(program_05_07.edited Chapter05/program_05_07/program_05_07.edited.c)

add_executable(program_05_08.edited Chapter05/program_05_08/program_05_08.edited.c)

add_executable(program_05_09.edited Chapter05/program_05_09/program_05_09.edited.c)

add_executable(program_05_10.edited Chapter05/program_05_10/program_05_10.edited.c)

add_executable(program_05_11.edited Chapter05/program_05_11/program_05_11.edited.c)

add_executable(program_05_12.edited Chapter05/program_05_12/program_05_12.edited.c)

add_executable(program_05_13.edited Chapter05/program_05_13/program_05_13.edited.c)

add_executable(program_05_14.edited Chapter05/program_05_14/program_05_14.edited.c)

add_executable(program_05_15.edited Chapter05/program_05_15/program_05_15.edited.c)

add_executable(program_05_16.edited Chapter05/program_05_16/program_05_16.edited.c)

add_executable(program_05_17.edited Chapter05/program_05_17/program_05_17.edited.c)

add_executable(program_05_18.edited Chapter05/program_05_18/program_05_18.edited.c)

add_executable(program_05_19.edited Chapter05/program_05_19/program_05_19.edited.c)

add_executable(program_05_20.edited Chapter05/program_05_20/program_05_20.edited.c)

add_executable(program_05_21.edited Chapter05/program_05_21/program_05_21.edited.c)

add_executable(program_05_22.edited Chapter05/program_05_22/program_05_22.edited.c)

add_executable(program_06_01.edited Chapter06/program_06_01/program_06_01.edited.c)

add_executable(program_06_02.edited Chapter06/program_06_02/program_06_02.edited.c)

add_executable(program_06_03.edited Chapter06/program_06_03/program_06_03.edited.c)

add_executable(program_06_04.edited Chapter06/program_06_04/program_06_04.edited.c)

add_executable(program_06_05.edited Chapter06/program_06_05/program_06_05.edited.c)

add_executable(program_06_06.edited Chapter06/program_06_06-to-06_10/program_06_06.edited.c)

add_executable(program_06_11.edited Chapter06/program_06_11/program_06_11.edited.c)

add_executable(main Chapter09/program_09_11-to-09_12/main.c)

add_executable(program_06_14.edited Chapter06/program_06_14/program_06_14.edited.c)

add_executable(program_06_17.edited Chapter06/program_06_17/program_06_17.edited.c)

add_executable(program_07_03.edited Chapter07/program_07_03/program_07_03.edited.c)

add_executable(program_07_04.edited Chapter07/program_07_04/program_07_04.edited.c)

add_executable(program_07_05.edited Chapter07/program_07_05/program_07_05.edited.c)

add_executable(program_07_06.edited Chapter07/program_07_06/program_07_06.edited.c)

add_executable(program_07_07.edited Chapter07/program_07_07/program_07_07.edited.c)

add_executable(program_08_01.edited Chapter08/program_08_01/program_08_01.edited.c)

add_executable(program_08_02.edited Chapter08/program_08_02/program_08_02.edited.c)

add_executable(program_08_03.edited Chapter08/program_08_03/program_08_03.edited.c)

add_executable(program_08_04.edited Chapter08/program_08_04/program_08_04.edited.c)

add_executable(program_08_05.edited Chapter08/program_08_05/program_08_05.edited.c)

add_executable(program_08_06.edited Chapter08/program_08_06/program_08_06.edited.c)

add_executable(program_08_07.edited Chapter08/program_08_07/program_08_07.edited.c)

add_executable(program_08_08.edited Chapter08/program_08_08/program_08_08.edited.c)

add_executable(program_09_02.edited Chapter09/program_09_01-to-09_02/program_09_02.edited.c)

add_executable(program_09_03-to-09_05 Chapter09/program_09_03-to-09_05/program_09_03-to-09_05.c)

add_executable(program_09_06.edited Chapter09/program_09_06/program_09_06.edited.c)

add_executable(program_09_07.edited Chapter09/program_09_07/program_09_07.edited.c)

add_executable(program_09_13.edited Chapter09/program_09_13/program_09_13.edited.c)

add_executable(program_09_14-to-09_16 Chapter09/program_09_14-to-09_16/program_09_14-to-09_16.c)

add_executable(program_10_01.edited Chapter10/program_10_01/program_10_01.edited.c)

add_executable(program_10_02.edited Chapter10/program_10_02/program_10_02.edited.c)
