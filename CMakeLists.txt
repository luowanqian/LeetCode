cmake_minimum_required(VERSION 3.9)
project(LeetCode)

set(CMAKE_CXX_STANDARD 11)

include_directories(Utilities)

set(PROBLEM_SOURCES 973_KClosestPointsToOrigin/solution1.cpp)
set(UTILITIES_SOURCE Utilities/BinaryTree.cpp Utilities/List.cpp 341_FlattenNestedListIterator/nested_list.h)
add_executable(LeetCode ${UTILITIES_SOURCE} ${PROBLEM_SOURCES})