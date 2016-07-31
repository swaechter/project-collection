project(plugintoolchain)

set(CMAKE_AUTOMOC ON)

set(PLUGINTOOLCHAIN_SRCS
  PluginToolchain.cpp
  PluginPage.cpp
)

add_definitions(-DPLUGINTOOLCHAIN_MAKE_LIBRARY)

add_library(plugintoolchain SHARED ${PLUGINTOOLCHAIN_SRCS})
target_link_libraries(plugintoolchain cdevstudioplatform)

set_target_properties(plugintoolchain PROPERTIES VERSION ${VERSION_NUMBER} SOVERSION ${VERSION_SONUMBER})

install(TARGETS plugintoolchain RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
