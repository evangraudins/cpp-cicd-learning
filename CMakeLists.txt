cmake_minimum_required(VERSION 3.20)
project(cpp_cicd_learning VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Main library
add_library(mathlib STATIC
    src/math/calculator.cpp
)
target_include_directories(mathlib PUBLIC include)

# Main executable
add_executable(app src/main.cpp)
target_link_libraries(app PRIVATE mathlib)

# Tests (using GoogleTest via FetchContent)
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(tests
    tests/test_calculator.cpp
)
target_link_libraries(tests PRIVATE mathlib GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(tests)
