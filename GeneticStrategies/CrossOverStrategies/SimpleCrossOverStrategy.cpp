//
// Created by z003j23c on 9/11/2018.
//

#include "SimpleCrossOverStrategy.h"
#include "../../GeneticCore/Population.h"

Population&& SimpleCrossOverStrategy::CreateChildren(std::vector<Chromosome> mating_pool){
    Population children_for_next_gen;
    for (int i = 0; i < mating_pool.size()/2; i++) {
        std::vector<Chromosome> parents = PickParentsUp(mating_pool);
        std::vector<Chromosome> children = PerformCrossOver(parents);

        std::copy(children.begin(), children.end(), std::back_inserter(children_for_next_gen.population_pool));
        children_for_next_gen.population_size += 2; //TODO check if it is still needed
    }

    return std::move(children_for_next_gen);
}

std::vector<Chromosome> SimpleCrossOverStrategy::PerformCrossOver(std::vector<Chromosome> parents){
    std::vector<Chromosome> chromosomes = std::vector<Chromosome>(2);
    int num = rand() % 5; // TODO make it correct
    for (int i = 0; i < 5; i++) { //TODO make it correct
        if (i <= num) {
            chromosomes[0].genes[i] = parents[0].genes[i];
            chromosomes[1].genes[i] = parents[1].genes[i];
        } else {
            chromosomes[0].genes[i] = parents[0].genes[i];
            chromosomes[1].genes[i] = parents[1].genes[i];
        }
    }

    return chromosomes;
}