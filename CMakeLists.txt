cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 17)

project(TinyMinecraft)

find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

file(GLOB_RECURSE CXX_FILES *.cpp)
add_executable(${PROJECT_NAME} ${CXX_FILES})

target_link_libraries(
    ${PROJECT_NAME}
    ${GLEW_LIBRARIES}
    glfw
)
