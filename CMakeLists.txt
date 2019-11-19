cmake_minimum_required(VERSION 2.8)

set(OpenGlLinkers -lglut -lGLU -lGL)
project(soft3d)
add_executable(soft3d main.cpp)
target_link_libraries(soft3d ${OpenGlLinkers})
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
#target_link_libraries(jarvis -lglut -lGL -lGLU)

include_directories( ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} )

target_link_libraries(soft3d ${OPENGL_LIBRARIES} ${GLUT_INCLUDE_DIRS} )
