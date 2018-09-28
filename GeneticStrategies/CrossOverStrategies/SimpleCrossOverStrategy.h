//
// Created by z003j23c on 9/11/2018.
//

#ifndef ONEMAXPROBLEM_SIMPLECROSSOVERSTRATEGY_H
#define ONEMAXPROBLEM_SIMPLECROSSOVERSTRATEGY_H

#include "../../GeneticCore/Chromosome.h"
#include "../../GeneticCore/Population.h"
#include "CrossOverStrategy.h"

class SimpleCrossOverStrategy : public CrossOverStrategy {
public:
    Population&& CreateChildren(std::vector<Chromosome>);
    std::vector<Chromosome> PerformCrossOver(std::vector<Chromosome>) override;

};




#endif //ONEMAXPROBLEM_SIMPLECROSSOVERSTRATEGY_H
