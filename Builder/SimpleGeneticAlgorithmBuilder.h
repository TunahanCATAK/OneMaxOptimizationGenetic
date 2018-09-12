//
// Created by z003j23c on 9/11/2018.
//

#ifndef ONEMAXPROBLEM_SIMPLEGENETICALGORITHMBUILDER_H
#define ONEMAXPROBLEM_SIMPLEGENETICALGORITHMBUILDER_H

#include "../main.cpp"

    class SimpleGeneticAlgorithmBuilder : public SimpleGeneticAlgorithmBuilder, public Builder {

    public:
        SimpleGeneticAlgorithmBuilder(Population& initial_pop, size_t max_gen_size) {
            _result = new GeneticAlgorithm(initial_pop, max_gen_size);
        }

        void setParentSelectionStrategy(ParentSelectionStrategy rep) {
            _result->setParentSelectionStrategy(rep);
        }

        void setCrossOverStrategy(CrossOverStrategy xover) {
            _result->setCrossOverStrategy(xover);
        }

        void setMutationStrategy(MutationStrategy mutation) {
            _result->setMutationStrategy(mutation);
        }
    };


#endif //ONEMAXPROBLEM_SIMPLEGENETICALGORITHMBUILDER_H
