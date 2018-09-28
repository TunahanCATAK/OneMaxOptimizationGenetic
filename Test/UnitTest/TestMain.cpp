//
// Created by z003j23c on 9/28/2018.
//
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../../GeneticCore/Chromosome.h"
#include <memory>
#include <typeinfo>
#include <string>

class TestFixtureChromosome{
public:
    //std::unique_ptr<Chromosome<std::string>> chromosome;

    TestFixtureChromosome(){
        //chromosome = std::unique_ptr<Chromosome>(new Chromosome());
    }

    ~TestFixtureChromosome(){

    }
};


SCENARIO_METHOD(TestFixtureChromosome, "Master fighter die", "[master_fighter_die]")
{
    GIVEN("A chromosome consists of string")
    {
        std::unique_ptr<Chromosome<std::string>> chromosome;

        WHEN("A chromosome created with a string constructure")
        {
            chromosome = std::unique_ptr<Chromosome<std::string>>();
            THEN("a new master fighter should be picked.")
            {
                CHECK(typeid(chromosome->genes.at(0)).name() == "class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >");
            }
        }
    }
}


