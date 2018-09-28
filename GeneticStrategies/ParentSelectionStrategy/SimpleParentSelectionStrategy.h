//
// Created by z003j23c on 9/11/2018.
//

#ifndef ONEMAXPROBLEM_SIMPLEPARENTSELECTIONSTRATEGY_H
#define ONEMAXPROBLEM_SIMPLEPARENTSELECTIONSTRATEGY_H

#include <iterator>
#include "../../GeneticCore/Chromosome.h"
#include "../../GeneticCore/Population.h"
#include "ParentSelectionStrategy.h"

class SimpleParentSelectionStrategy : public ParentSelectionStrategy {

public:
    void FillMatingPool(Population&, std::vector<Chromosome>&);
};


#endif //ONEMAXPROBLEM_SIMPLEPARENTSELECTIONSTRATEGY_H
