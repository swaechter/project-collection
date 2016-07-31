project(cdevstudio)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(data)

set(CMAKE_AUTOMOC ON)

set(CDEVSTUDIO_SRCS
  main.cpp
  CDevStudio.cpp
  PluginDialog.cpp
  HelpDialog.cpp
  AboutDialog.cpp
  GeneralPage.cpp
)

set(CDEVSTUDIO_UI_IN
  PluginDialog.ui
  HelpDialog.ui
  AboutDialog.ui
)

set(CDEVSTUDIO_RESOURCE_IN
  Resource.qrc
)

qt5_wrap_ui(CDEVSTUDIO_UI_OUT ${CDEVSTUDIO_UI_IN})

qt5_add_resources(CDEVSTUDIO_RESOURCE_OUT ${CDEVSTUDIO_RESOURCE_IN})

add_executable(cdevstudio WIN32 ${CDEVSTUDIO_SRCS} ${CDEVSTUDIO_UI_OUT} ${CDEVSTUDIO_RESOURCE_OUT})
target_link_libraries(cdevstudio cdevstudioplatform)

install(TARGETS cdevstudio RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
