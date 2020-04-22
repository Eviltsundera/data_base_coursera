cmake_minimum_required(VERSION 3.15)
project(data_base)

set(CMAKE_CXX_STANDARD 17)

add_executable(data_base main.cpp date.h date.cpp database.h database.cpp token.h token.cpp node.h condition_parser.h condition_parser.cpp test_runner.h condition_parser_test.cpp node.cpp)