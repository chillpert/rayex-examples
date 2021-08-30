cmake_minimum_required(VERSION 3.16.2)
project("Rayex-Examples" VERSION 1.0.0)

# Tell CMake where to find the rayex repository. 
# You do not need to do anything if your folder structure looks like this:
# |
# |--- rayex
# |--- rayex-examples
set(PATH_TO_RAYEX ${PROJECT_SOURCE_DIR}/../rayex)

# Include all necessary rayex headers
include(${PATH_TO_RAYEX}/include/CMakeLists.txt)

# rayex-examples
add_executable(example ${PROJECT_SOURCE_DIR}/main.cpp ${IMGUI_SOURCES})

# Paths to libs
target_link_directories(example PRIVATE
  ${RAYEX_EXTERNAL_LINK_DIRS}

  $<$<STREQUAL:${CMAKE_SYSTEM_NAME},Linux>:${PATH_TO_RAYEX}/build>
  # TODO: do not hard-code, fix output under Windows to unify
  $<$<STREQUAL:${CMAKE_SYSTEM_NAME},Windows>:${PATH_TO_RAYEX}/build/Debug>
  
)

# Include directories for example
target_include_directories(example PRIVATE
  ${PROJECT_SOURCE_DIR}/include
  ${RAYEX_INCLUDE_DIRS}
)

# Link all necessary libs
target_link_libraries(example
  ${RAYEX_LIBRARY}
  ${RAYEX_EXTERNAL_LIBRARIES}
)

# Rayex requires C++20
set_target_properties(example PROPERTIES
  CXX_STANDARD 20
)

# Copy assets to binary location (this will be obsolete in the future as soon as relative paths are working properly)
file(GLOB ASSETS_TO_COPY "${PROJECT_SOURCE_DIR}/assets/*")
file(COPY ${ASSETS_TO_COPY} DESTINATION ${PROJECT_SOURCE_DIR}/build)
file(COPY ${PATH_TO_RAYEX}/shaders DESTINATION ${PROJECT_SOURCE_DIR}/build)