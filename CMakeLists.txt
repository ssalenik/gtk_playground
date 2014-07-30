project( test_gui )
cmake_minimum_required(VERSION 2.8)
set(CMAKE_BUILD_TYPE debug)

##### LIB STUFF #####
#find_package( OpenCV REQUIRED core imgproc)
find_package(PkgConfig REQUIRED)

pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
#pkg_check_modules(LIBDC1394-2 REQUIRED libdc1394-2 )

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
include_directories(${GTK3_INCLUDE_DIRS})
#include_directories(${LIBDC1394-2_INCLUDE_DIRS})

# Add other flags to the compiler
add_definitions(${GTK3_CFLAGS_OTHER})

# include source headers
include_directories (${PROJECT_SOURCE_DIR}/src)

set(SOURCES 
	${PROJECT_SOURCE_DIR}/src/test_gui.c )

add_executable( test_gui ${SOURCES})
target_link_libraries( test_gui ${GTK3_LIBRARIES} )
