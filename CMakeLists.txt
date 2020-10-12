cmake_minimum_required(VERSION 3.13)
project(learnopengl)


set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_EXE_LINKER_FLAGS /NODEFAULTLIB:\"MSVCRT\")
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

include_directories(includes)

link_directories(
        lib/glfw
        lib/assimp
)

add_executable(learnopengl
        main.cpp
        glad.c
        Shader.cpp
        Shader.h
        stb_image.cpp
        stb_image.h
        Camera.cpp
        Camera.h
        Mesh.cpp
        Mesh.h
        Model.cpp
        Model.h)

target_link_libraries(learnopengl assimp-vc142-mtd glfw3 opengl32)