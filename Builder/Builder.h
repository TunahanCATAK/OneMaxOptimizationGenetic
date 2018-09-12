//
// Created by z003j23c on 9/11/2018.
//

#ifndef ONEMAXPROBLEM_BUILDER_H
#define ONEMAXPROBLEM_BUILDER_H


class Builder {

public:
    virtual void setReproductionStrategy(ReproductionStrategy rep) = 0;

    virtual void setCrossOverStrategy(CrossOverStrategy xover) = 0;

    virtual void setMutationStrategy(MutationStrategy mutation) = 0;

    GeneticAlgorithm *getGeneticAlgorithm()
    {
        return _result;
    }

protected:
    GeneticAlgorithm* _result;
};


#endif //ONEMAXPROBLEM_BUILDER_H
