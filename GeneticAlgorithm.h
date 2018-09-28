//
// Created by z003j23c on 9/11/2018.
//

#ifndef ONEMAXPROBLEM_GENETICALGORITHM_H
#define ONEMAXPROBLEM_GENETICALGORITHM_H

#include <stdlib.h>     /* srand, rand */
#include <ostream>
#include <vector>
#include "GeneticCore/Chromosome.h"
#include "GeneticStrategies/CrossOverStrategies/CrossOverStrategy.h"
#include "GeneticStrategies/MutationStrategies/MutationStrategy.h"
#include "GeneticStrategies/SurvivalStrategies/SurvivalSelectionStrategy.h"
#include "GeneticStrategies/ParentSelectionStrategy/ParentSelectionStrategy.h"
class GeneticAlgorithm {
public:
    int max_generation_count;
    int generation = 0;
    std::vector<Population> generations;
    std::vector<Chromosome> mating_pool;
    ParentSelectionStrategy* parentSelectionStrategy;
    CrossOverStrategy* xOverStrategy;
    MutationStrategy* mutationStrategy;
    SurvivalSelectionStrategy* survivalStrategy;

    GeneticAlgorithm(Population&, unsigned int);

    bool moreGenerations();
    void setParentSelectionStrategy(ParentSelectionStrategy*);
    void setCrossOverStrategy(CrossOverStrategy*);
    void setMutationStrategy(MutationStrategy*);
    void setSurvivalSelectionStrategy(SurvivalSelectionStrategy*);


    void startEvolution();
};




#endif //ONEMAXPROBLEM_GENETICALGORITHM_H
