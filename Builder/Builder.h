//
// Created by z003j23c on 9/11/2018.
//

#ifndef ONEMAXPROBLEM_BUILDER_H
#define ONEMAXPROBLEM_BUILDER_H

#include "../GeneticStrategies/ParentSelectionStrategy.h"
#include "../GeneticStrategies/CrossOverStrategies/CrossOverStrategy.h"
#include "../GeneticStrategies/MutationStrategies/MutationStrategy.h"
#include "../GeneticAlgorithm.h"

class Builder {

public:
    virtual void setParentSelectionStrategy(ParentSelectionStrategy* rep) = 0;

    virtual void setCrossOverStrategy(CrossOverStrategy* xover) = 0;

    virtual void setMutationStrategy(MutationStrategy* mutation) = 0;

    GeneticAlgorithm* getGeneticAlgorithm()
    {
        return _result;
    }

protected:
    GeneticAlgorithm* _result;
};


#endif //ONEMAXPROBLEM_BUILDER_H
