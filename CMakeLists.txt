cmake_minimum_required(VERSION 3.10)
project(OneMaxProblem)

set(CMAKE_CXX_STANDARD 14)

add_executable(OneMaxProblem  main.cpp GeneticStrategies/ GeneticCore/ Builder/ GeneticAlgorithm.cpp)