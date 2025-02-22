
cmake_minimum_required(VERSION 3.10)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(cppBrowser)

file(GLOB SOURCES "src/*.cpp")
add_executable(browser ${SOURCES})

target_include_directories(browser PRIVATE ${PROJECT_BINARY_DIR}/src ${PROJECT_SOURCE_DIR}/include)
