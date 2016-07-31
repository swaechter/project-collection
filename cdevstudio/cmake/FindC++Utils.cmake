# Global compiler settings

# Enable C++11
if(NOT MSVC)
  set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
endif()
