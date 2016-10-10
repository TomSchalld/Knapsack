cmake_minimum_required(VERSION 3.6)
project(Knapsack)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cpp Knapsack_logic.cpp Knapsack_logic.h)
#set(SOURCE_FILES main.cpp knap_Inst.cpp knap_Inst.h knap_Item.cpp knap_Item.h ops.cpp ops.h bruteforce.cpp bruteforce.h)
add_executable(Knapsack ${SOURCE_FILES})