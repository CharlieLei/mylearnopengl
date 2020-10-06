cmake_minimum_required(VERSION 3.13)
project(learnopengl)


set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

include_directories(
        includes/glad
        includes/glfw
        includes/stbImage
)

link_directories(lib/glfw)

add_executable(learnopengl main.cpp glad.c Shader.cpp Shader.h stb_image.cpp stb_image.h)

target_link_libraries(learnopengl glfw3 opengl32)