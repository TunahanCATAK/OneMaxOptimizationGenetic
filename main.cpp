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
#include "GeneticStrategies/CrossOverStrategies/SimpleCrossOverStrategy.h"
using namespace std;

static int GENE_SIZE = 5;



int main(){
    /* initialize random seed: */
    srand (time(NULL));

    Population pop = Population(100);
    auto ga_builder = SimpleGeneticAlgorithmBuilder(pop, 500);
    ga_builder.setParentSelectionStrategy(new SimpleParentSelectionStrategy());
    ga_builder.setCrossOverStrategy(new SimpleCrossOverStrategy());

    GeneticAlgorithm ga = *ga_builder.getGeneticAlgorithm();
    ga.startEvolution();

    std::for_each(begin(ga.generations), end(ga.generations), [](Population gen){
        std::cout << "Average: " << gen.population_average << std::endl;
    });
    //Mater mater = Mater(pop);
}