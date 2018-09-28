//
// Created by z003j23c on 9/11/2018.
//

#ifndef ONEMAXPROBLEM_SIMPLEGENETICALGORITHMBUILDER_H
#define ONEMAXPROBLEM_SIMPLEGENETICALGORITHMBUILDER_H

#include "Builder.h"

class SimpleGeneticAlgorithmBuilder : public Builder {
public:
    SimpleGeneticAlgorithmBuilder(Population&, size_t);
    void setParentSelectionStrategy(ParentSelectionStrategy*);
    void setCrossOverStrategy(CrossOverStrategy*);
    void setMutationStrategy(MutationStrategy*);
};


#endif //ONEMAXPROBLEM_SIMPLEGENETICALGORITHMBUILDER_H
