project(cdevstudioplatform)

set(CMAKE_AUTOMOC ON)

set(CDEVSTUDIOPLATFORM_SRCS
  Platform.cpp
  IPlatform.cpp
  plugin/PluginManager.cpp
  plugin/PluginContainer.cpp
  plugin/IPlugin.cpp
  project/ProjectManager.cpp
  project/Project.cpp
  ui/Window.cpp
  ui/MenuBar.cpp
  ui/TabWidget.cpp
  ui/Settings.cpp
  ui/SettingsPage.cpp
  utils/Backend.cpp
)

add_definitions(-DCDEVSTUDIOPLATFORM_MAKE_LIBRARY)

add_library(cdevstudioplatform SHARED ${CDEVSTUDIOPLATFORM_SRCS})
target_include_directories(cdevstudioplatform PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(cdevstudioplatform Qt5::Widgets)

set_target_properties(cdevstudioplatform PROPERTIES VERSION ${VERSION_NUMBER} SOVERSION ${VERSION_SONUMBER})

install(TARGETS cdevstudioplatform RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
