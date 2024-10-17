# Add your main project files
set(SOURCES main.cpp ${GLAD_SOURCE})

# Create the executable
add_executable(DigCreate WIN32 ${SOURCES})

# Link libraries (OpenGL, GLFW, and GLAD)
target_link_libraries(DigCreate glfw ${OPENGL_LIBRARIES})
