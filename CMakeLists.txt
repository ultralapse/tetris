cmake_minimum_required(VERSION 3.10)
project(Tetris)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Werror -pedantic -g -O3)
endif()

# BOOST
find_package(Boost REQUIRED COMPONENTS unit_test_framework)
include_directories(${Boost_INCLUDE_DIRS})

# Get all the files
file(GLOB_RECURSE SOURCES "src/*.cpp" "lib/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.hpp" "lib/*.hpp")
file(GLOB_RECURSE TEST_SOURCES "tests/*.cpp")

add_custom_target(
    lint
    COMMAND cpplint ${SOURCES} ${HEADERS} ${TEST_SOURCES}
    COMMENT "Running cpplint"
)

# Main executable compilation
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} sfml-graphics sfml-window sfml-system)

# Prevent double inclusion of main
list(FILTER SOURCES EXCLUDE REGEX "main.cpp")

# Test files compilation
add_executable(test ${TEST_SOURCES} ${SOURCES} ${HEADERS})
target_link_libraries(test ${Boost_LIBRARIES})
