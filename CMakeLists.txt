cmake_minimum_required(VERSION 3.13)
project(learnopengl)


set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

include_directories(
        includes/glad
        includes/glfw
)

link_directories(lib/glfw)

add_executable(learnopengl main.cpp glad.c)

target_link_libraries(learnopengl glfw3 opengl32)