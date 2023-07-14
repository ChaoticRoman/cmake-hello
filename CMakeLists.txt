cmake_minimum_required(VERSION 3.22)
project(hello)

set(CMAKE_CXX_STANDARD 17)

# If CMAKE_CXX_STANDARD_REQUIRED is set to FALSE (or is not set at all, in which
# case it defaults to FALSE), and the compiler doesn't support the standard
# specified by CMAKE_CXX_STANDARD, then CMake will fall back to a lower standard
# if available
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(hello
    src/low/low.cpp
    src/mid/mid.cpp
    src/main.cpp
)

add_subdirectory(tests)
