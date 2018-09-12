//
// Created by z003j23c on 9/4/2018.
#include <stdlib.h>     /* srand, rand */
#include <ostream>
#include <algorithm>
#include <iterator>
#include <random>
#include "GeneticStrategies/ParentSelectionStrategy.h"
#include "GeneticCore/Population.h"
#include "GeneticAlgorithm.h"
#include "Builder/Builder.h"
#include "Builder/SimpleGeneticAlgorithmBuilder.h"
#include "GeneticStrategies/SimpleParentSelectionStrategy.h"
using namespace std;

static int GENE_SIZE = 5;



int main(){
    /* initialize random seed: */
    srand (time(NULL));

    Population pop = Population(100);
    auto sGA = SimpleGeneticAlgorithmBuilder(pop, 500);
    sGA.setParentSelectionStrategy(new SimpleParentSelectionStrategy());

    ga.startEvolution();

    std::for_each(begin(ga.generations), end(ga.generations), [](Population gen){ std::cout << "Average: " << ga.population_average << std::endl;});
    //Mater mater = Mater(pop);
}