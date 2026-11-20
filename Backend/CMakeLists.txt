cmake_minimum_required(VERSION 3.16)
project(code_ide_backend LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads REQUIRED)

add_executable(code_ide_server
    src/main.cpp
)

target_include_directories(code_ide_server PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(code_ide_server PRIVATE Threads::Threads)