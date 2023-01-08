cmake_minimum_required(VERSION 3.9)
project(LeetCode)

set(CMAKE_CXX_STANDARD 11)

include_directories(Utilities)

set(PROBLEM_SOURCES 501-600/543_DiameterOfBinaryTree/solution2.cpp)
set(UTILITIES_SOURCE Utilities/BinaryTree.cpp Utilities/List.cpp Utilities/Print.cpp)
#set(UTILITIES_SOURCE Utilities/BinaryTree2.cpp Utilities/List.cpp)
add_executable(leetcode ${UTILITIES_SOURCE} ${PROBLEM_SOURCES})