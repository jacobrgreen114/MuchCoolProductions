cmake_minimum_required (VERSION 3.20)

project ("MuchCoolProductions")


add_subdirectory("external")


set (CMAKE_C_STANDARD 17)
set (CMAKE_CXX_STANDARD 20)

add_subdirectory ("rndr")
