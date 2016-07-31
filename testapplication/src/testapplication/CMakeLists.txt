cmake_minimum_required(VERSION 2.8)
project(testapplication)

find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../)

add_subdirectory(data)

set(CMAKE_AUTOMOC ON)

set(SRC_TESTAPPLICATION
  main.cpp
  TestApplication.cpp
  DialogResourceText.cpp
  DialogUi.cpp
)

set(SRC_UI_TESTAPPLICATION
  TestApplication.ui
  DialogUi.ui
)

set(SRC_RESOURCE_TESTAPPLICATION
  Resource.qrc
)

qt5_wrap_ui(HDR_UI_TESTAPPLICATION ${SRC_UI_TESTAPPLICATION})

qt5_add_resources(HDR_RESOURCE_TESTAPPLICATION ${SRC_RESOURCE_TESTAPPLICATION})

add_executable(testapplication ${SRC_TESTAPPLICATION} ${HDR_RESOURCE_TESTAPPLICATION} ${HDR_UI_TESTAPPLICATION})
target_link_libraries(testapplication staticlibrary sharedlibrary Qt5::Widgets Qt5::Core)

install(TARGETS testapplication RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
