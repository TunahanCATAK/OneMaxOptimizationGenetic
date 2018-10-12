//
// Created by ctsnz0060 on 08.10.2018.
//

#include "catch.hpp"
#include "../../GeneticCore/Population.h"

template <typename  T>
using ptr_population = std::unique_ptr<Population<T>>;

class TestFixturePopulation{
public:
    TestFixturePopulation(){

    }

    ~TestFixturePopulation(){

    }
};

SCENARIO_METHOD(TestFixturePopulation, "Population Initialization with int", "[population_init]")
{
    GIVEN("A Population consists of int")
    {
        ptr_population<int> population;

        WHEN("A Population created with a int constructor")
        {
            population = ptr_population<int>(new Population<int>(5));

            THEN("New population is initialized")
            {
                CHECK(population.get()->population_size == 5);
            }
        }
    }
}