cmake_minimum_required(VERSION 3.11)
project(html-parser)

cmake_policy(SET CMP0054 NEW)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

message(STATUS ${CMAKE_BUILD_TYPE})

# Build type flags
set(CMAKE_CXX_FLAGS_DEBUG "-g3")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
string(APPEND CMAKE_CXX_FLAGS " -Wall -Wextra -pedantic -Werror")

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Setup conan
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(NO_OUTPUT_DIRS TARGETS)

# Public libraries needed for executables
add_library(lib
    src/lexer/tokenizer.cc
    src/parser/htmlParser.cc
    src/ast/pageElement.cc
    src/ast/tag.cc)
target_include_directories(lib PUBLIC include)

# Make CLI executable link against library
# add_executable(${PROJECT_NAME} src/cli/cli.cc)
# target_link_libraries(${PROJECT_NAME} PUBLIC lib)

# Examples executable
# add_executable(wikipedia examples/wikipedia.cc)
# target_link_libraries(wikipedia PUBLIC lib)

# Same here for tests
add_executable(tests tests/htmlParserTest.cc)
target_link_libraries(tests PUBLIC lib CONAN_PKG::catch2)
