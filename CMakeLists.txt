cmake_minimum_required(VERSION 2.8)

set(OpenGlLinkers -lglut -lGLU -lGL)
project(soft3d)
add_executable(soft3d main.cpp main.h Cena.h Cena.cpp)
target_link_libraries(soft3d ${OpenGlLinkers})
