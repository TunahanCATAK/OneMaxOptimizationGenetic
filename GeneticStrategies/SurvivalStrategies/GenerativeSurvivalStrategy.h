//
// Created by z003j23c on 9/21/2018.
//

#ifndef ONEMAXPROBLEM_GENERATIVESURVIVALSTRATEGY_H
#define ONEMAXPROBLEM_GENERATIVESURVIVALSTRATEGY_H
#include "SurvivalSelectionStrategy.h"

class GenerativeSurvivalStrategy : public SurvivalSelectionStrategy{
public:
    GenerativeSurvivalStrategy(Population& newIndividuals):NewIndividuals(newIndividuals){};
    Population&& pickIndividuals4NextGen(){

    }
public:
    Popolation& NewIndividuals;
};


#endif //ONEMAXPROBLEM_GENERATIVESURVIVALSTRATEGY_H
