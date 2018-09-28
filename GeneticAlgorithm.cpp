//
// Created by z003j23c on 9/11/2018.
//

#include "GeneticAlgorithm.h"

GeneticAlgorithm::GeneticAlgorithm(Population &initial_pop, unsigned int max_gen_size): max_generation_count(max_gen_size) {
    generations.push_back(initial_pop);
}

bool GeneticAlgorithm::moreGenerations(){
    return max_generation_count-- != 0;
}

void GeneticAlgorithm::setParentSelectionStrategy(ParentSelectionStrategy* rep){
    this->parentSelectionStrategy = rep;
}

void GeneticAlgorithm::setCrossOverStrategy(CrossOverStrategy* xover){
    this->xOverStrategy = xover;
}

void GeneticAlgorithm::setMutationStrategy(MutationStrategy* mutation) {
    this->mutationStrategy = mutation;
}

void GeneticAlgorithm::setSurvivalSelectionStrategy(SurvivalSelectionStrategy* survival) {
    this->survivalStrategy = survival;
}

void GeneticAlgorithm::startEvolution(){
    while(moreGenerations()){
        //ParentSelection
        parentSelectionStrategy->FillMatingPool(generations[generation] , mating_pool);
        //CrossOver
        Population new_population = xOverStrategy->CreateChildren(mating_pool);
        //survivalStrategy->pickIndividuals4NextGen()
        generations.push_back(new_population);
        //Mutation
        //mutationStrategy.Mutate(new_population); TODO Not yet Implemented
        //SurvivalSelection
        //auto survived_chromosomes = survivalStrategy.PerformSurvivalSelection(new_population); //TODO Not yet implemented
        //generations.push_back(survived_chromosomes);
        generation++;
    }

}