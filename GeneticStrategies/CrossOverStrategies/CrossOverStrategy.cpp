//
// Created by z003j23c on 9/11/2018.
//


#include <vector>
#include "CrossOverStrategy.h"
#include "../../GeneticCore/Chromosome.h"

std::vector<Chromosome> CrossOverStrategy::PickParentsUp(std::vector<Chromosome> mating_pool){
    int rand1 = rand() % mating_pool.size();
    int rand2 = rand() % mating_pool.size();

    std::vector<Chromosome> result;
    result.push_back(mating_pool[rand1]);
    result.push_back(mating_pool[rand2]);

    return result;
}