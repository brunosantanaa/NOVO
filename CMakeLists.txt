cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_COMPILER gcc)

project(NOVO)

file(GLOB sources "src/*.c")
file(GLOB headers "inc/*.h")

add_executable(${PROJECT_NAME} ${sources} ${headers})

target_include_directories(${PROJECT_NAME} PUBLIC "inc")
