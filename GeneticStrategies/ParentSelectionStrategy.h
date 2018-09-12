//
// Created by z003j23c on 9/11/2018.
//

#ifndef ONEMAXPROBLEM_PARENTSELECTIONSTRATEGY_H
#define ONEMAXPROBLEM_PARENTSELECTIONSTRATEGY_H


class ParentSelectionStrategy {

public:
    virtual std::vector<Chromosome> FillMatingPool(Population& population, std::vector<Chromosome> mating_pool) = 0;
};


#endif //ONEMAXPROBLEM_PARENTSELECTIONSTRATEGY_H
