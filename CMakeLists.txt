cmake_minimum_required(VERSION 3.10)
project(OneMaxProblem)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS  -std=c++14)

add_executable(OneMaxProblem
        main.cpp
        Builder/SimpleGeneticAlgorithmBuilder.h
        Builder/SimpleGeneticAlgorithmBuilder.cpp
        Builder/
        GeneticStrategies/
        GeneticStrategies/CrossOverStrategies/CrossOverStrategy.cpp
        GeneticStrategies/CrossOverStrategies/CrossOverStrategy.h
        GeneticStrategies/CrossOverStrategies/SimpleCrossOverStrategy.cpp
        GeneticStrategies/CrossOverStrategies/SimpleCrossOverStrategy.h
        GeneticCore/Chromosome.cpp
        GeneticCore/Chromosome.h
        GeneticCore/Population.cpp
        GeneticCore/Population.h
        GeneticCore/
        GeneticAlgorithm.cpp
        )