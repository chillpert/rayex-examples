cmake_minimum_required(VERSION 3.16.2)
project("Rayex-Examples" VERSION 1.0.0)

# Tell CMake where to find the rayex repository. 
# You do not need to do anything if your folder structure looks like this:
# |
# |--- rayex
# |--- rayex-examples
set(PATH_TO_RAYEX ${PROJECT_SOURCE_DIR}/../rayex)

# It is advised to include the CMakeLists.txt inside the 'include' folder that comes 
# with the pre-built binaries or the rayex repository of course.
#
# This file will set the following variables:
# 
# RAYEX_INCLUDE_DIRS  - all project headers
# RAYEX_LIBRARIES     - all libraries (third party + rayex itself)
# RAYEX_LINK_DIRS     - all directories of the above libraries 

include(${PATH_TO_RAYEX}/include/CMakeLists.txt)

# rayex-examples
add_executable(example ${PROJECT_SOURCE_DIR}/main.cpp)

# Paths to libs
target_link_directories(example PRIVATE
  ${RAYEX_LINK_DIRS}  
)

# Include directories for example
target_include_directories(example PRIVATE
  ${PROJECT_SOURCE_DIR}/include
  ${RAYEX_INCLUDE_DIRS}
)

# Link all necessary libs
target_link_libraries(example
  ${RAYEX_LIBRARIES}
)

# Rayex requires C++20
set_target_properties(example PROPERTIES
  CXX_STANDARD 20
)

# Copy assets to binary location (this will be obsolete in the future as soon as relative paths are working properly)
file(GLOB ASSETS_TO_COPY "${PROJECT_SOURCE_DIR}/assets/*")
file(COPY ${ASSETS_TO_COPY} DESTINATION ${PROJECT_SOURCE_DIR}/build)
file(COPY ${PATH_TO_RAYEX}/shaders DESTINATION ${PROJECT_SOURCE_DIR}/build)