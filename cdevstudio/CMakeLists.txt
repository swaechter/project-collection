cmake_minimum_required(VERSION 2.8.11)
project(cdevstudio-workspace)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(C++Utils REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(VERSION_NUMBER 0.0.8)
set(VERSION_SONUMBER 0)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)

add_subdirectory(src)
add_subdirectory(doc)
