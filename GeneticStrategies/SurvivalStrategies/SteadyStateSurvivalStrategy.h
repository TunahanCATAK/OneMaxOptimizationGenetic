//
// Created by mcangny on 22/09/18.
//

#ifndef ONEMAXPROBLEM_STEADYSTATESURVIVALSTRATEGY_H
#define ONEMAXPROBLEM_STEADYSTATESURVIVALSTRATEGY_H

#include "SurvivalSelectionStrategy.h"
#include "../../GeneticCore/Population.h"

class SteadyStateSurvivalStrategy : public SurvivalSelectionStrategy{
public:
    SteadyStateSurvivalStrategy(Population& oldIndv, Population& newIndv) :
            old_individuals(oldIndv) , new_individuals(newIndv){};

public:
    Population& old_individuals;
    Population& new_individuals;
};
#endif //ONEMAXPROBLEM_STEADYSTATESURVIVALSTRATEGY_H
