project(pluginproject)

set(CMAKE_AUTOMOC ON)

set(PLUGINPROJECT_SRCS
  PluginProject.cpp
  ProjectTemplate.cpp
  PluginPage.cpp
  CreateProjectDialog.cpp
)

set(PLUGINPROJECT_RESOURCE_IN
  PluginProjectResource.qrc
)

qt5_add_resources(PLUGINPROJECT_RESOURCE_OUT ${PLUGINPROJECT_RESOURCE_IN})

add_definitions(-DPLUGINPROJECT_MAKE_LIBRARY)

add_library(pluginproject SHARED ${PLUGINPROJECT_SRCS} ${PLUGINPROJECT_RESOURCE_OUT})
target_link_libraries(pluginproject cdevstudioplatform)

set_target_properties(pluginproject PROPERTIES VERSION ${VERSION_NUMBER} SOVERSION ${VERSION_SONUMBER})

install(TARGETS pluginproject RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
