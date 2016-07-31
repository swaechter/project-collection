project(testapplication)
cmake_minimum_required(VERSION 2.8)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules)

find_package(Testapplication REQUIRED)

add_subdirectory(src)
add_subdirectory(doc)
