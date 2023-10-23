cmake_minimum_required(VERSION 3.0)

project(NUOS)

file(GLOB_RECURSE DEF_FILES src/*.h*)
file(GLOB_RECURSE SRC_FILES src/*.c*)

include_directories(src)
add_subdirectory(lib/MinSocket)
add_executable(NUOSTest ${DEF_FILES} ${SRC_FILES})

target_link_libraries(NUOSTest MinimalSocket)