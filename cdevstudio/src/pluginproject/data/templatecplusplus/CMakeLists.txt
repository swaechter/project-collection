cmake_minimum_required(VERSION 2.8.9)
project(helloworld)

set(HELLOWORLD_SRCS
  main.cpp
)

add_executable(helloworld ${HELLOWORLD_SRCS})
