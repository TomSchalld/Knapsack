cmake_minimum_required(VERSION 3.6)
project(Knapsack)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cpp Knapsack_logic.cpp Knapsack_logic.h rs/BackPack.cpp rs/BackPack.h rs/Package.cpp rs/Package.h rs/Sack.cpp rs/Sack.h rs/Instance.cpp rs/Instance.h rs/DataImport.cpp rs/DataImport.h rs/Instances.cpp rs/Instances.h rs/BranchAndBound.cpp rs/BranchAndBound.h)
add_executable(Knapsack ${SOURCE_FILES})