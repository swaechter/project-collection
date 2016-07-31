cmake_minimum_required(VERSION 2.8)
project(staticlibrary)

find_package(Qt5Widgets REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_AUTOMOC ON)

set(SRC_STATICLIBRARY
  StaticLibrary.cpp
)

add_library(staticlibrary STATIC ${SRC_STATICLIBRARY})
target_link_libraries(staticlibrary Qt5::Widgets)

set_target_properties(staticlibrary PROPERTIES VERSION 0.1.0 SOVERSION 0)

install(TARGETS staticlibrary RUNTIME DESTINATION ${PROJECT_EXECUTABLE_PREFIX} LIBRARY DESTINATION ${PROJECT_LIBRARY_PREFIX} ARCHIVE DESTINATION ${PROJECT_LIBRARY_PREFIX})
install(FILES StaticLibrary.h DESTINATION include)
