# TODO: simplify everything

cmake_minimum_required(VERSION 3.16.2)
set(PROJECT_NAME "Rayex-Examples")
project(${PROJECT_NAME} VERSION 0.1.0)

set(CMAKE_BUILD_TYPE Debug)

# TODO: Simplify by only having to specify the path to rayex repo
set(RAYEX_LIBRARY_PATH ${PROJECT_SOURCE_DIR}/../rayex/build/Debug)
set(RAYEX_HEADER_PATH ${PROJECT_SOURCE_DIR}/../rayex/include)
set(RAYEX_EXTERNAL_LIBS_PATH ${PROJECT_SOURCE_DIR}/../rayex/include/external/libs)
set(RAYEX_SHADERS_PATH ${PROJECT_SOURCE_DIR}/../rayex)

add_executable(example ${PROJECT_SOURCE_DIR}/main.cpp ${FILES_EXAMPLE})

target_link_directories(example PUBLIC
  ${RAYEX_LIBRARY_PATH}
  ${RAYEX_EXTERNAL_LIBS_PATH}
)

# Include directories for example
target_include_directories(example PRIVATE
  ${PROJECT_SOURCE_DIR}/include
  ${RAYEX_HEADER_PATH}
  ${RAYEX_HEADER_PATH}/external
  ${RAYEX_HEADER_PATH}/external/imgui
)

target_link_libraries(example
  librayex.so
  SDL2main
  SDL2
)

target_compile_definitions(example PRIVATE
  PATH_TO_ASSETS="${PROJECT_SOURCE_DIR}/assets/"
  PATH_TO_EXECUTABLE="${PROJECT_SOURCE_DIR}/build/Debug/"
  PATH_TO_RAYEX_SHADERS="${RAYEX_SHADERS_PATH}/"
)

set_target_properties(example PROPERTIES
  CXX_STANDARD 20

  ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build/${CMAKE_BUILD_TYPE}"
  LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build/${CMAKE_BUILD_TYPE}"
  RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build/${CMAKE_BUILD_TYPE}"
)

# WARNING: On Windows the output folder is created twice for whatever reason. So the post-build copy command was adjusted accordingly.
# Copy DLLs to binary location in post build for Windows
if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
add_custom_command(
  TARGET example
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
          ${PROJECT_SOURCE_DIR}/include/external/libs/SDL2.dll
          ${PROJECT_SOURCE_DIR}/build/${CMAKE_BUILD_TYPE}/${CMAKE_BUILD_TYPE}/SDL2.dll
  COMMENT "Running POST_BUILD action: Copying SDL2d.dll to binary location"
  )

add_custom_command(
  TARGET example
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
          ${PROJECT_SOURCE_DIR}/include/external/libs/ktx.dll
          ${PROJECT_SOURCE_DIR}/build/${CMAKE_BUILD_TYPE}/${CMAKE_BUILD_TYPE}/ktx.dll
  COMMENT "Running POST_BUILD action: Copying ktx.dll to binary location"
  )
endif()