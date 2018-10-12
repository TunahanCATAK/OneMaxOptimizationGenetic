cmake_minimum_required(VERSION 3.10)
project(OneMaxProblem)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS  -std=c++14)

add_executable(TestOneMaxProblem

        catch.hpp
        ../../GeneticCore/Chromosome.h
        ../../GeneticCore/Population.h
        ../../GeneticCore/Chromosome.cpp
        ../../GeneticCore/Population.cpp
        TestChromosome.cpp
        TestPopulation.cpp)