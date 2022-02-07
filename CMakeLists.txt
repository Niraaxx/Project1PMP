cmake_minimum_required(VERSION 3.10)

project("Parser Command Line Options"
  LANGUAGES CXX
)

find_package(Threads)
include(CTest)

# Compile googltest as static lib
add_library(googletest1 STATIC
  googletest/googletest/src/gtest-all.cc
)

target_compile_options(googletest1
  PRIVATE
    "-g" "-O2"
)

target_include_directories(googletest1
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest"
)

add_executable(testParser
  Option.cc
  Parser.cc
  testParser.cc
)

target_include_directories(testParser
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest"
)

target_compile_options(testParser
  PRIVATE
  "-Wall" "-Wextra" "-g" "-fsanitize=address,undefined"
)

target_compile_features(testParser
  PUBLIC
    cxx_std_17
)

set_target_properties(testParser
  PROPERTIES
    CXX_EXTENSIONS OFF
    LINK_FLAGS "-fsanitize=address,undefined"
)

target_link_libraries(testParser
  PRIVATE
    googletest1
    Threads::Threads
)

include(GoogleTest)
gtest_discover_tests(testParser)
