//
// Created by z003j23c on 9/11/2018.
//

#ifndef ONEMAXPROBLEM_PARENTSELECTIONSTRATEGY_H
#define ONEMAXPROBLEM_PARENTSELECTIONSTRATEGY_H

#include "../../GeneticCore/Population.h"
#include "../../GeneticCore/Chromosome.h"


class ParentSelectionStrategy {

public:
    virtual void FillMatingPool(Population& population, std::vector<Chromosome>& mating_pool) = 0;
};


#endif //ONEMAXPROBLEM_PARENTSELECTIONSTRATEGY_H
