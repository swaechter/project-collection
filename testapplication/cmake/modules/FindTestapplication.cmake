# This module files simplifies the configuration of the project and provides some important paths

# Use one directory for all executables and binaries
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)

# Include the GNU installation directories
include(GNUInstallDirs)

# Set the executable installation prefix
if(CMAKE_INSTALL_BINDIR)
  set(PROJECT_EXECUTABLE_PREFIX ${CMAKE_INSTALL_BINDIR})
else()
  set(PROJECT_EXECUTABLE_PREFIX "bin")
endif()

# Set the library installation prefix
if(CMAKE_INSTALL_LIBDIR)
  set(PROJECT_LIBRARY_PREFIX ${CMAKE_INSTALL_LIBDIR})
else()
  set(PROJECT_LIBRARY_PREFIX "lib")
endif()

# Set the include installation prefix
if(CMAKE_INSTALL_INCLUDEDIR)
  set(PROJECT_INCLUDES_PREFIX ${CMAKE_INSTALL_INCLUDEDIR})
else()
  set(PROJECT_INCLUDES_PREFIX "includes")
endif()

# Set the desktop file installation prefix
set(PROJECT_DESKTOP_PREFIX "share/applications")

# Set the man page installation prefix
set(PROJECT_MAN_PREFIX "share/man/man1")
