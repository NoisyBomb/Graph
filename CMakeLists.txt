cmake_minimum_required(VERSION 3.26)
project(untitled6)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled6 main.cpp)

set(SFML_DIR "C:\\Users\\Vladimir\\CLionProjects\\lib\\sfml\\GCC 13.1.0 MinGW (SEH) - 64-bit\\SFML-2.6.0\\lib\\cmake\\SFML")

target_link_libraries(untitled6 sfml-graphics)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2.6 REQUIRED graphics network audio window system)