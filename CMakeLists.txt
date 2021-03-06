cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 17)

project(TinyMinecraft)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)
find_package(Boost REQUIRED COMPONENTS system filesystem)
find_package(OpenCV REQUIRED)
find_package(nlohmann_json 3.2.0 REQUIRED)

file(GLOB_RECURSE CXX_FILES *.cpp)
add_executable(${PROJECT_NAME} ${CXX_FILES})

include_directories("source")

target_link_libraries(
    ${PROJECT_NAME}
    ${OPENGL_LIBRARIES}
    ${GLEW_LIBRARIES}
    glfw
    ${Boost_LIBRARIES}
    ${OpenCV_LIBS}
    nlohmann_json::nlohmann_json
)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
