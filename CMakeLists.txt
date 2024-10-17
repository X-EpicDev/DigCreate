cmake_minimum_required(VERSION 3.29)
project(DigCreate)

set(CMAKE_CXX_STANDARD 17)

# Add GLFW submodule
add_subdirectory(dependencies)

# Find OpenGL
find_package(OpenGL REQUIRED)

# Include OpenGL directories
include_directories(${OPENGL_INCLUDE_DIRS})

# Use the GLAD files bundled with GLFW
set(GLAD_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/dependencies/glfw/deps/glad")
set(GLAD_SOURCE "${CMAKE_SOURCE_DIR}/dependencies/glfw/deps/glad/gl.h")

# Include directories for GLAD and GLFW
include_directories(${GLAD_INCLUDE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/dependencies/glfw/include)

add_subdirectory(src)