cmake_minimum_required(VERSION 3.9)
project(LeetCode)

set(CMAKE_CXX_STANDARD 11)

include_directories(Utilities)

set(PROBLEM_SOURCES 1101-1200/1191_K-ConcatenationMaximumSum/solution1.cpp)
set(UTILITIES_SOURCE Utilities/BinaryTree.cpp Utilities/List.cpp)
#set(UTILITIES_SOURCE Utilities/BinaryTree2.cpp Utilities/List.cpp)
add_executable(LeetCode ${UTILITIES_SOURCE} ${PROBLEM_SOURCES})