//
// Created by z003j23c on 9/11/2018.
//

#include "SimpleGeneticAlgorithmBuilder.h"

SimpleGeneticAlgorithmBuilder::SimpleGeneticAlgorithmBuilder(Population &initial_pop, size_t max_gen_size) {
    _result = new GeneticAlgorithm(initial_pop, max_gen_size);
}

void SimpleGeneticAlgorithmBuilder::setParentSelectionStrategy(ParentSelectionStrategy *rep) {
    _result->setParentSelectionStrategy(rep);
}

void SimpleGeneticAlgorithmBuilder::setCrossOverStrategy(CrossOverStrategy *xover) {
    _result->setCrossOverStrategy(xover);
}

void SimpleGeneticAlgorithmBuilder::setMutationStrategy(MutationStrategy *mutation) {
    _result->setMutationStrategy(mutation);
}