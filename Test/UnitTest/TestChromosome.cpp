//
// Created by z003j23c on 9/28/2018.
//
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../../GeneticCore/Chromosome.h"
#include <memory>
#include <typeinfo>
#include <string>
#include <functional>
#include <algorithm>

class my_type{
public:
    int m_x;
};

template <typename  T>
using ptr_chromosome = std::unique_ptr<Chromosome<T>>;

class TestFixtureChromosome{
public:
    //std::unique_ptr<Chromosome<std::string>> chromosome;


    TestFixtureChromosome(){
        //chromosome = std::unique_ptr<Chromosome>(new Chromosome());
    }

    ~TestFixtureChromosome(){

    }
};


SCENARIO_METHOD(TestFixtureChromosome, "Chromosome Initialization with String", "[chromosome_init]")
{
    GIVEN("A chromosome consists of string")
    {
        ptr_chromosome<std::string> chromosome;

        WHEN("A chromosome created with a string constructor")
        {
            //chromosome = type_ptr_chromosome_string(new Chromosome<std::string>());
            chromosome = ptr_chromosome<std::string>(new Chromosome<std::string>());
            chromosome.get()->genes.push_back("tunahan");
            THEN("a new master fighter should be picked.")
            {
                CHECK(chromosome.get()->genes.size() == 1);
            }
        }
    }
}

SCENARIO_METHOD(TestFixtureChromosome, "Chromosome Initialization with int", "[chromosome_init]")
{
    GIVEN("A chromosome consists of int")
    {
        ptr_chromosome<int> chromosome;

        WHEN("A chromosome created with a string constructure")
        {
            chromosome = ptr_chromosome<int>(new Chromosome<int>());
            chromosome.get()->genes.push_back(5);
            THEN("a new master fighter should be picked.")
            {
                CHECK(chromosome.get()->genes.size() == 1);
            }
        }
    }
}

/*SCENARIO_METHOD(TestFixtureChromosome, "Chromosome Initialization with user defined type", "[chromosome_init]")
{
    GIVEN("A chromosome consists of my_type")
    {
        ptr_chromosome<my_type> chromosome;

        WHEN("A chromosome created with a string constructure")
        {
            chromosome = ptr_chromosome<my_type>(new Chromosome<my_type>());
            chromosome.get()->genes.push_back(my_type());
            THEN("a new master fighter should be picked.")
            {
                CHECK(chromosome.get()->genes.size() == 1);
            }
        }
    }
}*/

SCENARIO_METHOD(TestFixtureChromosome, "Initialize a chromosome with a given gene size", "[chromosome_init]")
{
    GIVEN("An int type chromosome with 5 genes")
    {
        ptr_chromosome<int> chromosome = ptr_chromosome<int>(new Chromosome<int>(5));

        WHEN("we tried to get gene size via vector and member")
        {
            int gene_size = chromosome.get()->gene_size;
            int gene_size_vector = chromosome.get()->genes.size();

            THEN("they should be equal to 5")
            {
                CHECK(gene_size == 5);
                CHECK(gene_size_vector == 5);
            }
        }
    }
}
/*
SCENARIO_METHOD(TestFixtureChromosome, "Initialize a user defined type chromosome with a given gene size", "[chromosome_init]")
{
    GIVEN("A user defined type chromosome with 5 genes")
    {
        ptr_chromosome<my_type> chromosome = ptr_chromosome<my_type>(new Chromosome<my_type>(5));

        WHEN("we tried to get gene size via vector and member")
        {
            int gene_size = chromosome.get()->gene_size;
            int gene_size_vector = chromosome.get()->genes.size();

            THEN("they should be equal to 5")
            {
                CHECK(gene_size == 5);
                CHECK(gene_size_vector == 5);
            }
        }
    }
}*/
static float fit(Chromosome<int>* c){
    return std::count(std::begin(c->genes), std::end(c->genes), 1);

}
SCENARIO_METHOD(TestFixtureChromosome, "Calculate Fitness Value with a given fitness function", "[chromosome_fitness]")
{
    GIVEN("A int type chromosome with 5 genes")
    {

        ptr_chromosome<int> chromosome = ptr_chromosome<int>(new Chromosome<int>(5));
        GIVEN("and given a fitness function for our chromosome data")
        {
            chromosome.get()->genes.at(0) = 1;
            chromosome.get()->genes.at(1) = 1;
            chromosome.get()->genes.at(2) = 0;
            chromosome.get()->genes.at(3) = 0;
            chromosome.get()->genes.at(4) = 1;


            Chromosome<int>::FitnessFunc = &fit;
            WHEN("we tried to calculate fitness value of the chromosome")
            {

                float fit_value = chromosome.get()->calculateFitness();

                THEN("it should be equal to ")
                {
                    CHECK((int)fit_value == 3);
                }
            }
        }

    }
}


/*
SCENARIO_METHOD(TestFixtureChromosome, "Can not be able to change gene vector from outside", "[chromosome_private_members]")
{
    GIVEN("An integer type chromosome with 5 genes")
    {
        ptr_chromosome<my_type> chromosome;

        WHEN("we tried to resize of ")
        {
            chromosome = ptr_chromosome<my_type>(new Chromosome<my_type>());
            chromosome.get()->genes.push_back(my_type());
            THEN("a new master fighter should be picked.")
            {
                CHECK(chromosome.get()->genes.size() == 1);
            }
        }
    }
}*/
