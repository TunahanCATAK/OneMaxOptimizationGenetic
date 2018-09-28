//
// Created by z003j23c on 9/11/2018.
//

#ifndef ONEMAXPROBLEM_CROSSOVERSTRATEGY_H
#define ONEMAXPROBLEM_CROSSOVERSTRATEGY_H

#include <vector>
#include <iterator>
#include "../../GeneticCore/Population.h"
#include "../../GeneticCore/Chromosome.h"

class CrossOverStrategy {
public:
    virtual Population&& CreateChildren(std::vector<Chromosome>) = 0;
    virtual std::vector<Chromosome> PerformCrossOver(std::vector<Chromosome>) = 0;
    virtual std::vector<Chromosome> PickParentsUp(std::vector<Chromosome>);
};



#endif //ONEMAXPROBLEM_CROSSOVERSTRATEGY_H
