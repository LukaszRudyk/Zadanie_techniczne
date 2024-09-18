cmake_minimum_required(VERSION 3.10)


project(MyProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_testing()
include_directories(include test)

add_executable(Main src/main.cpp src/validator.cpp src/converter.cpp src/number_proccessor.cpp)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip  # You can use the latest version
)
FetchContent_MakeAvailable(googletest)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(Tests test/main_tests.cpp src/converter.cpp src/validator.cpp)
target_link_libraries(Tests ${GTEST_LIBRARIES} pthread)

target_link_libraries(Tests)

add_test(NAME Tests COMMAND Tests)
