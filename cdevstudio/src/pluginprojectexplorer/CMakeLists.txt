project(pluginprojectexplorer)

set(CMAKE_AUTOMOC ON)

set(PLUGINPROJECTEXPLORER_SRCS
  PluginProjectExplorer.cpp
  ProjectExplorer.cpp
  PluginPage.cpp
)

add_definitions(-DPLUGINPROJECTEXPLORER_MAKE_LIBRARY)

add_library(pluginprojectexplorer SHARED ${PLUGINPROJECTEXPLORER_SRCS})
target_link_libraries(pluginprojectexplorer cdevstudioplatform)

set_target_properties(pluginprojectexplorer PROPERTIES VERSION ${VERSION_NUMBER} SOVERSION ${VERSION_SONUMBER})

install(TARGETS pluginprojectexplorer RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
