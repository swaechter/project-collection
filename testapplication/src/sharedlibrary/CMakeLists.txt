cmake_minimum_required(VERSION 2.8)
project(sharedlibrary)

find_package(Qt5Core REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_AUTOMOC ON)

set(SRC_SHAREDLIBRARY
  SharedLibrary.cpp
)

add_definitions(-DSHAREDLIBRARY_EXPORT)

add_library(sharedlibrary SHARED ${SRC_SHAREDLIBRARY})
target_link_libraries(sharedlibrary Qt5::Core)

set_target_properties(sharedlibrary PROPERTIES VERSION 0.1.0 SOVERSION 0)

install(TARGETS sharedlibrary RUNTIME DESTINATION ${PROJECT_EXECUTABLE_PREFIX} LIBRARY DESTINATION ${PROJECT_LIBRARY_PREFIX} ARCHIVE DESTINATION ${PROJECT_LIBRARY_PREFIX})
install(FILES SharedLibrary.h SharedLibraryExport.h DESTINATION include)
